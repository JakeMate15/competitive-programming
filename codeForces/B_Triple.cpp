#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;


#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define deb(a)          cout << a << "\n"
#define debl(a)         cout << a << " "
#define pb              push_back
#define umap            gp_hash_table

typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9+7;
const int mx = 1e9;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void sol(){
    int n;
    cin>>n;
    unordered_map<int, int, custom_hash> a;

    int res = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;

        if(a[x] >= 3) {
            res = x;
        }
    }

    deb(res);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	cin>>t;
	while(t--){
		sol();
	}

	return 0;
}