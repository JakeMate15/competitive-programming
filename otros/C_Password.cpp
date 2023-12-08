#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// Constantes
const ll N = 2e6 + 5;
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

void sol () {
    preCal();
    string s; 
    cin >> s;
    int n = s.size();

    HashedString hs(s);
    string res = "";
    vector<ll> a(1e6 + 5);

    for(int i = 2 ; i < n ; i++){
        ll val = hs.get(0, n - i);

        if(val != hs.get(i, n)) 
            continue;
        for(int j = 1; j < i; j++){
            if(val != hs.get(j, j + n - i)) 
                continue;
            res = s.substr(i);
            break;
        }
        if(res != "") {
            // cout << "Just a legend\n";
            // return; 
            break;
        }
    }

    if(res == "") 
        cout << "Just a legend\n";
    else 
        cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}