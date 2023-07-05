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

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    
    forn(i, n) {
        forn(j, m) {
            cin >> a[i * m + j];
        }
    }
    
    int l = 0, r = n * m;
    while (l < r) {
        int mid = (l + r + 1)/2;
        
        int ant = 0;
        bool ok = true;
        forn(i, n) {
            forn(j, m) {
                if (a[i * m + j] < mid) {
                    if (ant > j) {
                        ok = false;
                        break;
                    }
                    ant = j;
                }
            }
            if (!ok) {
                break;
            }
        }
        
        if (ok) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    debug(l);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}