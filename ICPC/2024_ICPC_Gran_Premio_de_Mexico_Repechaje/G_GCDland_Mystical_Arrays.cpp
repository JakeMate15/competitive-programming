#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

vector<int> primos, primoMin;
void criba(int n) {
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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int g = 0;
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
        g = gcd(g, x);
    }

    criba(3165);

    map<int, int> cnt;
    for (auto &x: arr) {
        x /= g;
        int a = x;

        for (auto p: primos) {
            if (p * p > x) {
                break;
            }

            if (x % p == 0) {
                if (cnt.count(p)) {
                    cout << "NO\n";
                    return 0;
                } else {
                    cnt[p] = 1;
                } 

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) {
            if (cnt.count(x) ) {
                cout << "NO\n";
                return 0;
            } else {
                cnt[x] = 1;
            }
        }
    }

    cout << "YES\n";

    return 0;
}
