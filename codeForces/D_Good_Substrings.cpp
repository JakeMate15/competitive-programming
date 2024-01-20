#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

// Constantes
const ll N = 2e5+1;
const ll MOD = 212345678987654321LL;
const ll base = 33;

// Operaciones
ll add(ll a, ll b) { 
    return ((a + b) % MOD + MOD) % MOD; 
}
ll mult(__int128 a, __int128 b) { 
    return ((a * 1LL *b) % MOD + MOD) % MOD; 
}
ll binpow(ll a, ll n){
    if(!n) 
        return 1;
    ll res = binpow(a, n>>1);
    res = mult(res, res);
    if(n & 1) 
        return mult(res, a);
    return res;
}

// Inverso modular
ll baseinv = binpow(base, MOD - 2);
ll pws[N];
ll inv[N];

class HashedString {
private:
    ll n;
    vector<ll> h;

public:
    HashedString(string s){
        n = s.size() + 1;
        h = vector<ll>(n);
        for(ll i = 1; i < n ; i++)
            h[i] = add(h[i - 1] , mult(pws[i], s[i - 1]));
    }

    ll get(ll l,ll r){ 
        return mult(add(h[r], -h[l]), inv[l]); 
    }
};

// Potencias de la base y sus inversos modulares
void preCal(){
    pws[0] = 1;
    inv[0] = 1;
    for(ll i = 1 ; i < N ; i++){
        pws[i] = mult(pws[i - 1], base);
        inv[i] = mult(inv[i - 1], baseinv);
    }
}

void sol(){
    preCal();
    string s, malos;
    int k, n;
    cin >> s >> malos >> k;

    n = sz(s);
    HashedString hs(s);
    set<ll> st;

    for(int i = 0; i < n; i++){
        int cuantos = 0;

        for(int j = i + 1 ; j <= n; j++){
            cuantos += malos[s[j - 1] - 'a'] == '0';
            if(cuantos > k)
                break;
            st.insert(hs.get(i, j));
        }

    }

    cout << sz(st) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}