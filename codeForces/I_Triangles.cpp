#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Fenwick {
    int n;
    vector<int> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, int v) { for (int i = x + 1; i <= n; i += i & -i) a[i - 1] += v; }
    int sum(int x) {
        int res = 0;
        for (int i = x; i > 0; i &= i - 1) res += a[i - 1];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c;
    cin >> r >> c;
    cin.get();
    
    vector<string> s(2 * r - 1);
    
    for (int i = 0; i < 2 * r - 1; ++i) {
        getline(cin, s[i]);
        s[i].resize(2 * c - 1, ' ');
    }
    
    auto solve = [&](int t) {
        ll ans = 0;
        
        vector<int> ru(c), lu(c), l(c);
        for (int i = 1; i < r; ++i) {
            vector<pair<int, int>> a;
            
            for (int j = (i % 2) ^ t; j < c; j += 2) {
                ru[j] = j + 1 < c && s[2 * i - 1][2 * j + 1] != ' ' ? ru[j + 1] + 1 : 0;
                lu[j] = j > 0 && s[2 * i - 1][2 * j - 1] != ' ' ? lu[j - 1] + 1 : 0;
                l[j] = j >= 2 && s[2 * i][2 * j - 1] != ' ' ? l[j - 2] + 1 : 0; 
                a.emplace_back(j + 2 * ru[j], j);
            }
            
            sort(a.begin(), a.end());
            Fenwick fen(c);
            
            for (int j = (i % 2) ^ t, k = 0; j < c; j += 2) {
                ans += fen.sum(j) - fen.sum(j - 2 * min(lu[j], l[j]));
                fen.add(j, 1);
                while (k < int(a.size()) && a[k].first <= j) 
                    fen.add(a[k++].second, -1);
            }
        }
        
        return ans;
    };
    
    ll ans = solve(0);
    reverse(s.begin(), s.end());
    ans += solve(!(r % 2));
    
    cout << ans << "\n";
    
    return 0;
}