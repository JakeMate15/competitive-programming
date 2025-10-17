#include<bits/stdc++.h>
using namespace std;

const int N = 101000; 
const int K = 333;

bool vis[N];
int nxt[N + 1][K];
vector<int> f[N];
vector<int> have[N];

void sol () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
        
    vector<int> allVec;
    for (int i = 0; i < n; i++) {
        if (a[i] >= K) {
            have[a[i]].push_back(i);
            if (!vis[a[i]]) {
                vis[a[i]] = true;
                allVec.push_back(a[i]);
            }
        }
    }
    
    for (int j = 0; j < K; j++) {
        nxt[n][j] = n;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < K; j++) {
            if (a[i] == j)
                nxt[i][j] = i;
            else
                nxt[i][j] = nxt[i + 1][j];
        }
    }
    
    sort(allVec.begin(), allVec.end());
    allVec.erase(unique(allVec.begin(), allVec.end()), allVec.end());
    
    while (q--) {
        int k, l, r;
        cin >> k >> l >> r;
        l--; r--;
        int64_t res = 0;
        while (l <= r) {
            int mn = 1E9;
            for (auto d : f[k]) {
                if (d < K) {
                    if (nxt[l][d] < mn)
                        mn = nxt[l][d];
                } else {
                    auto it = lower_bound(have[d].begin(), have[d].end(), l);
                    if (it != have[d].end() && *it < mn)
                        mn = *it;
                }
            }
            if (mn <= r) {
                res += 1LL * k * (mn - l);
                while (k % a[mn] == 0)
                    k /= a[mn];
                res += k;
                l = mn + 1;
            } else {
                res += 1LL * k * (r - l + 1);
                break;
            }
        }
        cout << res << "\n";
    }
    
    for (auto i : allVec) {
        vis[i] = false;
        have[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i)
            f[j].push_back(i);
    }

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}