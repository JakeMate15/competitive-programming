#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))
#define forn(i,n) for(ll i=0;i<n;i++)

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5+5;

vector<int> grafo[N];
vector<bool> vis(N,false);
int n,m;

void dfs(int origen){
    if(vis[origen]) return;
    vis[origen] = true;

    for(auto u: grafo[origen]){
        dfs(u);
    }
}

void sol(){
    cin>>n>>m;

    int a,b;
    forn(i,m){
        cin>>a>>b;
        grafo[a].pb(b);
    }

    int res = 0;
    int primero = -1;
    stack<int> ciudades;
    for(int i=1; i<n; i++){
        if(!vis[i]){
            dfs(i);
            res++;

            if(primero==-1){
                primero = i;
            }
            else{
                ciudades.push(i);
            }
        }
    }

    cout << res-1 << endl;
    while(!ciudades.empty()){
        cout << primero << " " << ciudades.top() << endl;
        ciudades.pop();
    }
}

int main(){
    //IO
    int t=1;//cin>>t;

    while(t--)
        sol();
}