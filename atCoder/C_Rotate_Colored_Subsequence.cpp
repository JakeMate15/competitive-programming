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

int n, m;
string s;
int c[200000];
vector<int> p[200001];

void sol(){
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) p[c[i]].push_back(i);
    
    string t(n, '?');
    for(int i = 1; i <= m; i++){
        int k = p[i].size();
        for(int j = 0; j < k; j++) t[p[i][(j+1)%k]] = s[p[i][j]];
    }
    cout << t << endl;
}

int main(){IO
	int t=1;
	//cin>>t;
	while(t--)  sol();
}