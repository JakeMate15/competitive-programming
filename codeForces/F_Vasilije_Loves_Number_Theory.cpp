#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

const int mx = 4e4;

vector<int> primes, lowest_prime;
void sieve(int n){
	lowest_prime.resize(n+1);
	for(int i = 2; i <= n; ++i){
		if(lowest_prime[i] == 0){
			primes.push_back(i);
			lowest_prime[i] = i;
		}
		for(int p : primes){
			int d = i * p;
			if(d > n) break;
			lowest_prime[d] = p;
			if(p == lowest_prime[i]){
				break;
			}
		}
	}
}

map<int, int> factorize(int x) {
    map<int, int> fac;

    for(auto p: primes) {
        int e = 0;
        while(x % p == 0) {
            e++;
            x /= p;
        }

        if(e) {
            fac[p] = e;
        }
    }

    if(x > 1) {
        fac[x] = 1;
    }

    return fac;
}

map<int, int> mul(map<int, int> a, map<int, int> b) {
    map<int, int> res = a;

    for(auto &[p, e]: b) {
        res[p] += e;
    }

    return res;
}

int get_num_divisors(map<int, int> a) {
    int ans = 1;

    for(auto [p, e]: a) {
        ans =  ans * (e + 1);
    }

    return ans;
}

bool is_divisor(map<int,int>& x, map<int,int>& d){
	for(auto [p,e]:d){
		if(!x.count(p)) return false;
		if(x[p] < e) return false;
	}
	return true;
}

void sol(){
    int n, q;
    cin >> n >> q;

    auto nF = factorize(n);

    while(q--) {
        int op, x;
        cin >> op;

        if(op == 1) {
            cin >> x;

            auto aux = factorize(x);
            nF = mul(nF, aux);

            int d = get_num_divisors(nF);
            aux = factorize(d);

            if(is_divisor(nF, aux)) {
                debln("YES");
            }
            else{
                debln("NO");
            }
        }
        else{
            nF = factorize(n);
        }
    }

    debln("");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    sieve(mx);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}