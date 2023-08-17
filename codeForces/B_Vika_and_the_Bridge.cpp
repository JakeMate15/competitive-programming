#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)	    v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 1e9+7;

void sol(){
    int n,k;
    cin>>n>>k;

    vi a(n);
    for(int &x: a)
        cin>>x;

    vi ultimo(k,-1);
    vi distMax(k), distMax2(k);
    forn(i,n) {
        int dist = i - ultimo[a[i] - 1];
        if (dist > distMax[a[i] - 1]) {
            distMax2[a[i] - 1] = distMax[a[i] - 1];
            distMax[a[i] - 1] = dist;
        } else if (dist > distMax2[a[i] - 1]) {
            distMax2[a[i] - 1] = dist;
        }
        ultimo[a[i] - 1] = i;
    }
    forn(i,k) {
        int dist = n - ultimo[i];
        if (dist > distMax[i]) {
            distMax2[i] = distMax[i];
            distMax[i] = dist;
        } else if (dist > distMax2[i]) {
            distMax2[i] = dist;
        }
    }
    int ans = 1e9;
    forn(i,k) {
        ans = min(ans, max((distMax[i] + 1) / 2, distMax2[i]));
    }
    debug(ans-1);
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  sol();
}