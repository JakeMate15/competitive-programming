#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)		v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int n;
    cin>>n;

    vector<vi> arbol(n+1);
    int res = 0;
    vi dp(n+1,0),blancos(n+1,0),negros(n+1,0);
    string s;

    fore(i,2,n){
        int u;
        cin>>u;
        arbol[u].push_back(i);
        arbol[i].push_back(u);
    }
    cin>>s;

    auto dfs = [&](int h, int p,auto&& dfs) -> void{
        if(s[h-1] == 'W')   blancos[h]++;
        else                negros[h]++;

        for(auto u: arbol[h]){
            if(u==p)    continue;
            dfs(u,h,dfs);
            blancos[h]+=blancos[u];
            negros[h]+=negros[u];
        }
        
        if(blancos[h] == negros[h])    res++;
    };

    dfs(1,0,dfs);
    debug(res);
}

int main(){
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}