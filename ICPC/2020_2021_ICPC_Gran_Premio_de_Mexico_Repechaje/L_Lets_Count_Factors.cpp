#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

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

map<int, int> factoriza(ll x) {
    map<int, int> res;
    for(ll p: primos) {
        if(p * p > x) {//Cuidado con el overflow, cambiar el tipo a la criba si es necesario
            break;
        }
        int e = 0;
        while(x % p == 0) {
            e++;
            x /= p;
        }

        if(e) {
            res[p] = e;
        }
    }
    
    if(x > 1) {//revisar los limites
        res[x] = 1;
    }

    return res;
}

void sol(){
    ll a, b;
    cin >> a >> b;

    auto aa = factoriza(a);
    auto bb = factoriza(b);

    for(auto [v, vv]: bb) {
        aa[v] += vv;
    }

    cout << sz(aa) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    criba(1e4);

    while(t--){
        sol();
    }

    return 0;
}