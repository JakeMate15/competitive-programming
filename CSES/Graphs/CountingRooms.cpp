#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";
#define pb push_back
#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))
#define forn(i,n) for(ll i=0;i<n;i++)

const int N = 1005;

typedef long long ll;
typedef pair<int,int> pii;

char grafo[N][N];
bool vis[N][N];
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};
string ds="RLDU";
string res = "";
int m,n;

struct estado{
    int x;
    int y;
    int d;

    void build(int xi, int yi, int di){
        x = xi;
        y = yi;
        d = di;
    }
};

int bfs(int h, int l,int xi,int yi){
    estado inicial;
    inicial.build(xi,yi,0);
    queue<estado> q;

    q.push(inicial);
    while(!q.empty()){
        estado actual = q.front();
        q.pop();

        if(grafo[actual.x][actual.y] == 'B'){
            return actual.d;
        }

        vis[actual.x][actual.y] = true;   
        forn(i,n){               
            int nuevox = actual.x + mx[i];    
            int nuevoy = actual.y + my[i];    

            if (nuevox >= 0 && nuevox < l && nuevoy >= 0 && nuevoy < h){   
                if (!vis[nuevox][nuevoy] && grafo[nuevox][nuevoy] != '#'){  
                    estado nuevo;
                    nuevo.build(nuevox, nuevoy, actual.d + 1);     
                    q.push(nuevo);

                    if(mx[i]==1)    res+="R";
                    if(mx[i]==-1)   res+="L";
                    if(my[i]==1)    res+="U";
                    if(my[i]==-1)   res+="D";
                }   
            }
        }
    }

    return -1;
}

void sol(){
    int xi,yi;
    cin>>n>>m;
    forn(i,n){
        forn(j,m){
            cin>>grafo[i][j];
            vis[i][j] = false;
            if(grafo[i][j] == 'A'){
                xi = i;
                yi = j;
            }
        }
    }

    int dist = bfs(m,n,xi,yi);

    if(dist<0){
        NO
    }
    else{
        YES
        cout << dist << endl;
        cout << res << endl;
    }
}

int main(){
    IO
    int t=1;//cin>>t;

    while(t--)
        sol();
}