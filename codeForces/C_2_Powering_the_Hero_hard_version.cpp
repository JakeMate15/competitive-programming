#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<n; i++)
#define fore(i,a,n) for(ll i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    int n;
    cin >> n;
    int s[n];
	
	priority_queue<int> pq;
	ll res = 0;
	
	forn (i, n) {
		cin >> s[i];
		if (!s[i]) {
			if (pq.size()) {
				res += pq.top();
				pq.pop();
			}
		} else {
			pq.push(s[i]);
		}
	}
	
	debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}