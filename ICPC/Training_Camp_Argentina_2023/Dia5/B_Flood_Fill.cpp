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
#define sz(a)       (int)a.size()

const int mx = 5050;
int n;
vi a;
int dp[mx][mx];

void sol(){
        cin>>n;
        forn(i,n){
                int lec; 
                cin>>lec;
                if (sz(a) && a[sz(a) - 1] == lec) 
                        continue;
                a.push_back(lec);
        }
        n = sz(a);

        fore(i,1,n) {
                for (int j = 0; i + j <= n; j++) {
                        if (i && j) {
                                if (a[i-1] == a[n-j])
                                        dp[i][j] = 1 + dp[i-1][j-1];
                        }
                        if(i)
                                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                        if (j>=1) 
                                dp[i][j] = max(dp[i][j], dp[i][j-1]);

                }
        }
        

        /*
        fore(i,1,n) {
                fore(j,1,n)
                        cout << dp[i][j] << " ";
                cout << endl;
        }
        */

        int mv = 0;
        forn(i,n)
                mv = max(mv, dp[i][n - 1 - i]);

        //debug(mv);
        debug(n-1-mv);
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}

/*

0 0 0 0 0 0 
1 1 1 1 0 0 
1 1 1 0 0 0 
1 1 0 0 0 0 
1 0 0 0 0 0 
0 0 0 0 0 0 
1
4



0 0 0 
0 0 0 
0 0 0 
0
2

*/