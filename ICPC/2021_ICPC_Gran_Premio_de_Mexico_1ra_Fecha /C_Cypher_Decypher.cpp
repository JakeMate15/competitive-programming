#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> primos, primoMin;
    int n = 1e6;
    primoMin.resize(n + 1);
    for(int i = 2; i <= n; i++) {
        if(primoMin[i] == 0) {
            primos.push_back(i);
            primoMin[i] = i;
        }

        for(int p: primos) {
            int d = i * p;
            if(d > n)   break;
            primoMin[d] = p;
            if(p == primoMin[i]) {
                break;
            }
        }
    }

    int t = 1;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        auto it1 = upper_bound(all(primos), r);
        auto it2 = lower_bound(all(primos), l);
        cout << it1 - it2 << "\n";;
    }

    return 0;
}