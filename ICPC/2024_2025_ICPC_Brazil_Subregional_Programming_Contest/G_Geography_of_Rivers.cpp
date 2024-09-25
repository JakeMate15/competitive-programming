#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    Node *left, *right, *parent;
    bool rev;

    // Data specific to the problem
    long long volume;
    int name; // The name (index) of the river with the largest volume in the subtree
    long long totalVolume;
    int maxName; // The name corresponding to the maximum volume in the subtree

    Node(int idx, long long vol) : left(nullptr), right(nullptr), parent(nullptr), rev(false),
                                   volume(vol), name(idx), totalVolume(vol), maxName(idx) {}
};

void push(Node* n) {
    if (n && n->rev) {
        swap(n->left, n->right);
        if (n->left) n->left->rev ^= true;
        if (n->right) n->right->rev ^= true;
        n->rev = false;
    }
}

void update(Node* n) {
    n->totalVolume = n->volume;
    n->maxName = n->name;
    if (n->left) {
        n->totalVolume += n->left->totalVolume;
        if (n->left->totalVolume > n->totalVolume - n->volume) {
            n->maxName = n->left->maxName;
        } else if (n->left->totalVolume == n->totalVolume - n->volume) {
            n->maxName = min(n->maxName, n->left->maxName);
        }
    }
    if (n->right) {
        n->totalVolume += n->right->totalVolume;
        if (n->right->totalVolume > n->totalVolume - n->volume) {
            n->maxName = n->right->maxName;
        } else if (n->right->totalVolume == n->totalVolume - n->volume) {
            n->maxName = min(n->maxName, n->right->maxName);
        }
    }
}

bool isRoot(Node* n) {
    return !n->parent || (n->parent->left != n && n->parent->right != n);
}

void rotate(Node* x) {
    Node* p = x->parent;
    Node* g = p->parent;
    push(p);
    push(x);
    if (p->left == x) {
        p->left = x->right;
        if (x->right) x->right->parent = p;
        x->right = p;
    } else {
        p->right = x->left;
        if (x->left) x->left->parent = p;
        x->left = p;
    }
    p->parent = x;
    x->parent = g;
    if (g) {
        if (g->left == p) g->left = x;
        if (g->right == p) g->right = x;
    }
    update(p);
    update(x);
}

void splay(Node* x) {
    push(x);
    while (!isRoot(x)) {
        Node* p = x->parent;
        Node* g = p->parent;
        if (!isRoot(p)) {
            if ((p->left == x) == (g->left == p)) rotate(p);
            else rotate(x);
        }
        rotate(x);
    }
}

void access(Node* x) {
    Node* last = nullptr;
    for (Node* y = x; y; y = y->parent) {
        splay(y);
        y->right = last;
        update(y);
        last = y;
    }
    splay(x);
}

void makeRoot(Node* x) {
    access(x);
    x->rev ^= true;
}

void link(Node* x, Node* y) {
    makeRoot(x);
    x->parent = y;
}

void cut(Node* x, Node* y) {
    makeRoot(x);
    access(y);
    if (y->left == x && !x->right) {
        y->left = nullptr;
        x->parent = nullptr;
        update(y);
    }
}

Node* findRoot(Node* x) {
    access(x);
    while (x->left) {
        push(x);
        x = x->left;
    }
    splay(x);
    return x;
}

void updateVolume(Node* x, long long delta) {
    makeRoot(x);
    x->volume += delta;
    update(x);
}

int queryMaxName(Node* x) {
    access(x);
    return x->maxName;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Node* nodes[2 * N + 1]; // Nodes from 1 to 2N

    for (int i = 1; i <= N; ++i) {
        long long vol;
        cin >> vol;
        nodes[i] = new Node(i, vol);
    }

    int total_nodes = N;

    for (int i = 1; i <= N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        int new_node = ++total_nodes;
        nodes[new_node] = new Node(new_node, 0); // Initial volume will be updated

        // Link the new node with its children
        link(nodes[a], nodes[new_node]);
        link(nodes[b], nodes[new_node]);

        // Update the volume and name of the new node
        makeRoot(nodes[new_node]);
        nodes[new_node]->volume = nodes[a]->totalVolume + nodes[b]->totalVolume;
        if (nodes[a]->totalVolume > nodes[b]->totalVolume)
            nodes[new_node]->name = nodes[a]->maxName;
        else if (nodes[b]->totalVolume > nodes[a]->totalVolume)
            nodes[new_node]->name = nodes[b]->maxName;
        else
            nodes[new_node]->name = min(nodes[a]->maxName, nodes[b]->maxName);
        update(nodes[new_node]);
    }

    int root_idx = total_nodes;
    cout << nodes[root_idx]->name << '\n';

    int Q;
    cin >> Q;
    while (Q--) {
        int n_i;
        long long q_i;
        cin >> n_i >> q_i;

        // Increase the volume at source node n_i
        updateVolume(nodes[n_i], q_i);

        // Since the volumes and names are updated during splay operations,
        // we can get the updated name at the root
        cout << queryMaxName(nodes[root_idx]) << '\n';
    }

    return 0;
}
