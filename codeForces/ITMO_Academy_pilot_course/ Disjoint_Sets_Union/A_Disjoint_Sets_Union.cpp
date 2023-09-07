#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct DSU{
    int n;
    vi padre,tam;

    DSU(int N): n(N+1), padre(N+1), tam(N+1,1){
        N++;
        while(N--)  padre[N] = N;
    }

    void make_set(int v){
        padre[v] = v;
        tam[v] = 1;
    }

    int find(int a){
        return a==padre[a]?a:padre[a]=find(padre[a]);
    }

    void join(int a, int b){
        a = find(a);
        b = find(b);

        if(a!=b){
            if(tam[a]>tam[b])   swap(a,b);
            n--;
            padre[a] = b;
            tam[b]+=tam[a];
        }
    }

    bool same(int a, int b){
        return find(a)==find(b);
    }

    int getTamU(int u){
        return tam[find(u)];
    }

    int numSets(){
        return n;
    }
};

void sol(){
    int n,q;
    cin>>n>>q;

    DSU ds(n);

    while(q--){
        string op;
        int u,v;
        cin>>op>>u>>v;

        if(op == "union"){
            ds.join(u,v);
        }
        else{
            if(ds.same(u,v))    debln("YES");
            else                debln("NO");
        }

    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}