#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    fore(i,1,n) cin>>a[i];
    fore(i,1,n) cin >> b[i];
    
    vector<int> maxAp1(n*2 + 1),maxAp2(n*2 + 1);
    int inicio= 1;

    fore(i,2,n){
        if (a[i] != a[i - 1]){
            maxAp1[a[i - 1]] = max(maxAp1[a[i - 1]], i - inicio);
            inicio= i;
        }
    }
    maxAp1[a[n]] = max(maxAp1[a[n]], n - inicio+ 1);


    inicio= 1;
    fore(i,2,n){
        if (b[i] != b[i - 1]){
            maxAp2[b[i - 1]] = max(maxAp2[b[i - 1]], i - inicio);
            inicio= i;
        }
    }
    maxAp2[b[n]] = max(maxAp2[b[n]], n - inicio+ 1);

    int ans = 0;
    fore(i,1,n*2)   ans = max(ans, maxAp1[i] + maxAp2[i]);

    debug(ans);
}


int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}