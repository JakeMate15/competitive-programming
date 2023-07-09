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

const int N = 1005;

int n,m;
char grafo[N][N];
bool vis[N][N];
int previo[N][N];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string dir = "URDL";

void bfs(pii inicio, pii fin){
    queue<pii> q;
    q.push(inicio);
    vis[inicio.f][inicio.s] = true;

    while(!q.empty()){
        pii actual = q.front();
        q.pop();

        forn(i,4){
            //aux representa el nodo al que se puede acceder
            pii aux = mp( actual.f+dx[i] , actual.s + dy[i] );
            if( aux.f<0 || aux.s<0 || aux.f>=n || aux.s>=m )    continue;
            if( grafo[aux.f][aux.s]=='#' )   continue;
            if( vis[aux.f][aux.s] ) continue;
            vis[aux.f][aux.s] = true;
            previo[aux.f][aux.s] = i;
            q.push(aux);
        }
    }

    /*
    forn(i,n){
        forn(j,m){
            cout << vis[i][j];
        }
        cout << endl;
    }

    cout << endl;

    forn(i,n){
        forn(j,m){
            cout << grafo[i][j];
        }
        cout << endl;
    }

    cout << endl;

    forn(i,n){
        forn(j,m){
            cout << previo[i][j];
        }
        cout << endl;
    }*/

    if(vis[fin.f][fin.s]){
        YES
        vector<int> recorrido;

        while(fin!=inicio){
            int direccion = previo[fin.f][fin.s];
            recorrido.pb(direccion);
            //Quitamos el reccorrido agregado anteiormente
            fin = mp( fin.f - dx[direccion], fin.s - dy[direccion] );
        }

        //cout << "Hola" << endl;

        reverse(all(recorrido));
        cout << recorrido.size() << endl;
        for(char c: recorrido)
            cout << dir[c];

        cout << endl;
    }
    else{
        NO
    }
    

}

void sol(){
    cin>>n>>m;
    pii inicio,fin;
    
    forn(i,n){
        forn(j,m){
            cin>>grafo[i][j];
            if(grafo[i][j] == 'A')
                inicio = mp(i,j);
            if(grafo[i][j] == 'B')
                fin = mp(i,j);
        }
    }

    //cout << inicio.f << " " << inicio.s << endl;
    //cout << fin.f << " " << fin.s << endl;

    bfs(inicio,fin);
}

int main(){
    //IO
    int t=1;//cin>>t;

    while(t--)
        sol();
}