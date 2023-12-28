#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

template <int p > struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }
 
	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e%(p-1));
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }
 
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<mod> mint;

const int N = 1e6;
vector<mint> fac(N + 5);

void sol() {
    int n, k;
    cin >> n >> k;
 
    vector<mint> a(n);
    map<int,int> rep;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;

        rep[a[i].v]++;
    }
 
    fac[0] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i;
    }
 
    mint q = 1;
    for(auto x: rep){
        q *= fac[x.second];
    }

    cout << (q / fac[n]).v << "\n";

    while(k--){
        int A, B;
        cin >> A >> B;
        A--;
 
        int keyR = a[A].v;
        if(keyR != B){
            if(!rep.count(B))   
                rep[B] = 0;
            if(rep[keyR] == 0)    
                (q /= 1);
            else                
                q /= rep[keyR];
        
            rep[keyR]--;
            rep[B]++;
            q *= rep[B];
            a[A] = B;
        }

        cout << (q / fac[n]).v << "\n";
 
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);

	int t = 1;
	//cin >> t;

	while(t--){
		sol();
	}

	return 0;
}