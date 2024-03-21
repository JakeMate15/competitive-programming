#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1E9 + 7;
const int MX = 1E5 + 5;

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

void sol () {
    int n;
    cin >> n;

    auto f = factoriza(n);
    int p = 0, i = 0;

    for (auto [primo, pot]: f) {
        if (pot & 1)    i++;
        else    p++;
    }

    cout << (p > i ? "Psycho Number" : "Ordinary Number") << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; 
    cin >> t;

    criba(1E4);

    for (auto p: primos) {
        cerr << p << " ";
        if (p >= 100)    break;
    }

    while (t--) {
        sol();
    }

    return 0;
}