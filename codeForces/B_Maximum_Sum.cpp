//https://codeforces.com/problemset/problem/1832/B
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int &x: a){
        cin>>x;
    }
    sort(all(a));
    
    lli pref[n+2];
    pref[0] = 0;
    fore(i,1,n+1)   pref[i] = pref[i-1] + a[i-1];
    pref[n+1] = pref[n];

    lli res = 0;
    fore(i,1,k+1){
        int l,r;
        l = (i-1)*2;
        r = (k+i)+2;
        cout << l << " " << r << endl;
        res = max(res, pref[l]-pref[r]);
    }

    //debug("\n\n");
    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}


/*

0 4
2 5
24
0 5
2 6
4 7
94035190449257
0 4
2 5
94035190449260
0 4
2 5
62
0 5
2 6
4 7
83
0 4
2 5


*/