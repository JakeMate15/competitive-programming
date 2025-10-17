#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val, prior, sz;
    Node *l, *r;
    Node(int v): val(v), prior(rand()), sz(1), l(nullptr), r(nullptr) {}
};

int getSize(Node* t) { return t ? t->sz : 0; }
void upd(Node* t) { if(t) t->sz = 1 + getSize(t->l) + getSize(t->r); }

void split(Node* t, int key, Node*& l, Node*& r) {
    if (!t) { l = r = nullptr; return; }
    if (getSize(t->l) >= key) {
        split(t->l, key, l, t->l);
        r = t;
        upd(r);
    } else {
        split(t->r, key - getSize(t->l) - 1, t->r, r);
        l = t;
        upd(l);
    }
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    r->l = merge(l, r->l);
    upd(r);
    return r;
}

void inorder(Node* t, vector<int>& arr) {
    if (!t) return;
    inorder(t->l, arr);
    arr.push_back(t->val);
    inorder(t->r, arr);
}

int64_t mergeCount(vector<int>& arr, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    int64_t inv = mergeCount(arr, l, m) + mergeCount(arr, m, r);
    vector<int> temp;
    int i = l, j = m;
    while (i < m && j < r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else { temp.push_back(arr[j++]); inv += (m - i); }
    }
    while (i < m) temp.push_back(arr[i++]);
    while (j < r) temp.push_back(arr[j++]);
    for (int k = l; k < r; k++) arr[k] = temp[k - l];
    return inv;
}

int64_t countInv(vector<int> arr) {
    return mergeCount(arr, 0, arr.size());
}

Node* build(vector<int>& arr) {
    Node* root = nullptr;
    for (int v : arr) root = merge(root, new Node(v));
    return root;
}

int64_t processRange(Node* root, int l, int r) {
    Node* rootCopy = root;

    Node *A, *B, *C;
    split(rootCopy, l, A, B);
    split(B, r - l + 1, B, C);

    Node *B1, *B2;
    split(B, 1, B1, B2);
    Node* B_shifted = merge(B2, B1);

    rootCopy = merge(A, merge(B_shifted, C));

    vector<int> temp;
    inorder(rootCopy, temp);
    cerr << "-------------------\n";
    cerr << l << " " << r << "\n";
    for (auto &x: temp) {
        cerr << x << " ";
    }
    cerr << "\n" << countInv(temp) << "\n";
    return countInv(temp);
}

void sol () {cerr << "===========\n";
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    Node* root = build(arr);
    int64_t mn = 1E18, l, r;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int64_t inv = processRange(root, i, j);
            // cerr << i << " " << j << " " << inv << "\n";
            if (inv < mn) {
                mn = inv;
                l = i;
                r = j;
            }
        }
    }

    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}