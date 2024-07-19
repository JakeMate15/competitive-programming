#include <bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;
typedef long double ld;

#define neutro  0.0
struct nodo {
    ld valor = neutro;
    string rang = "";
    char tipo = 'd';
    int tam;

    nodo(ld v, string r) : valor(v), rang(r) {
        tam = 1;
    }
    nodo() {
        tam = 1;
    }

    nodo operator+(const nodo &b) {
        nodo res;
        res.valor = valor + b.valor;
        res.rang = rang + "," + b.rang; 
        res.tam = tam + b.tam;
        return res;
    }

    string toString() const {
        return rang;
    }
};

template<typename T>
struct SegmentTree {
    int n;
    vector<nodo> st;

    SegmentTree(int n, vector<T> a) : n(n) {
        st.resize(n << 1);
        for(int i = 0; i < n; i++)
            st[n + i] = nodo(a[i], to_string(i + 1));
        for(int i = n - 1; i > 0; i--)
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    void update(int i, T v) {
        for (st[i += n] = nodo(v); i >>= 1; )
            st[i] = st[i << 1] + st[i << 1 | 1];
    }

    nodo query(int l, int r) {//[l, r)
        nodo resl, resr;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)   resl = resl + st[l++];
            if(r & 1)   resr = st[--r] + resr;
        }
        return resl + resr;
    }

    string imprimirSegmentTree(int i = 1) {
        if (i >= n) {
            return st[i].toString();
        }

        string izq = imprimirSegmentTree(i << 1);
        string der = imprimirSegmentTree(i << 1 | 1);

        if (i < n && (i << 1 | 1) < st.size()) {
            return "{d:" + izq + "," + der + "}";
        } else {
            return izq + "," + der;
        }
    }

    ld calculateFitness(ld expectedSum) {
        nodo root = query(0, n);
        ld calculatedSum = root.valor;
        
        // Accuracy score
        ld A = pow(max(abs(calculatedSum - expectedSum) / max(abs(expectedSum), pow(10, -200)), pow(10, -20)), 0.05);
        
        // Weight calculation
        int W = calculateWeight(root);

        // Memory penalty
        ld P = calculateMemoryPenalty(root);

        // Cost and data score
        ld C = W + P / (n - 1);
        ld D = sqrt(10.0 * C + 0.5);
        
        // Final score
        return D / A;
    }

    int calculateWeight(const nodo &root) {
        // Calculate the weight based on the type of operations
        int weight = 0;
        if (root.tipo == 'd') {
            weight = 4;
        } else if (root.tipo == 's') {
            weight = 2;
        } else if (root.tipo == 'h') {
            weight = 1;
        }
        // Recursively calculate the weight for nested nodes
        for (const auto &child : parseNodes(root.rang)) {
            weight += calculateWeight(child);
        }
        return weight;
    }

    ld calculateMemoryPenalty(const nodo &root) {
        // Implement memory penalty calculation
        // Here you should parse the indices and calculate the penalties
        vector<int> indices = parseIndices(root.rang);
        ld penalty = 0.0;
        int penaltyCounter = 1;
        for (size_t i = 0; i < indices.size(); i += 16) {
            int base = indices[i];
            for (size_t j = i + 1; j < i + 16 && j < indices.size(); ++j) {
                if (abs(indices[j] - base) > 15) {
                    penalty += penaltyCounter / 20000.0;
                    penaltyCounter++;
                }
            }
        }
        return penalty;
    }

    vector<int> parseIndices(const string &rang) {
        // Parse indices from the range string
        vector<int> indices;
        size_t pos = 0, found;
        while((found = rang.find_first_of(",{}", pos)) != string::npos) {
            if (isdigit(rang[pos])) {
                indices.push_back(stoi(rang.substr(pos, found - pos)));
            }
            pos = found + 1;
        }
        if (isdigit(rang[pos])) {
            indices.push_back(stoi(rang.substr(pos)));
        }
        return indices;
    }

    vector<nodo> parseNodes(const string &rang) {
        // Parse nested nodes from the range string
        // This is a simplified version, you'll need to implement a proper parser
        vector<nodo> nodes;
        // Your implementation here
        return nodes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ld> nums(n);
    for (auto &x: nums) {
        cin >> x;
    }

    SegmentTree<ld> st(n, nums);

    // cout << fixed << setprecision(10) << "\n";
    // cout << st.query(0, n).valor << "\n";

    cout << st.imprimirSegmentTree() << "\n";


    ld expectedSum = 39.6; // Example expected sum
    ld fitness = st.calculateFitness(expectedSum);
    cerr << "Fitness: " << fitness << endl;
    
    return 0;
}
