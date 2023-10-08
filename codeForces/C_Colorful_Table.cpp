#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

void sol(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> l(k, n), r(k, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = i;
    }

    vector<int> sl = l, sr = r;
    for(int i = k - 2; i >= 0; i--) {
        sl[i] = min(sl[i], sl[i + 1]);
        sr[i] = max(sr[i], sr[i + 1]);
    }

    for(int i = 0; i < k; i++) {
        if(l[i] > r[i]) {
            deb(0);
        }
        else {
            deb(2 * (sr[i] - sl[i] + 1));
        }
    }

    debln("");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}