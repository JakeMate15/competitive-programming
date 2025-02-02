#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

int main() {
    int n, m, o;
    cin >> n >> m >> o;

    vector<int> ing(n);
    for (int i = 0; i < n; ++i) {
        cin >> ing[i];
    }

    vector<vector<pair<int, int>>> plat(m);
    for (int i = 0; i < m; ++i) {
        int mi;
        cin >> mi;
        plat[i].resize(mi);
        for (int j = 0; j < mi; ++j) {
            int idx, qty;
            cin >> idx >> qty;
            plat[i][j] = {idx - 1, qty}; 
        }
    }

    int res = 0;
    for (int i = 0; i < o; ++i) {
        int oi;
        cin >> oi;
        vector<int> ords(n, 0);
        
        for (int j = 0; j < oi; ++j) {
            int pI;
            cin >> pI;
            pI--;
            for (auto& j : plat[pI]) {
                ords[j.first] += j.second;
            }
        }

        bool ok = true;
        for (int k = 0; k < n; ++k) {
            if (ords[k] > ing[k]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int k = 0; k < n; ++k) {
                ing[k] -= ords[k];
            }
            res++;
        } else {
            break;
        }
    }

    cout << res << "\n";

    return 0;
}
