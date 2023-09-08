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

ll sum(int numero){
    if(!numero) return 0;

    ll res = 0;

    while (numero != 0) {
        res += numero % 10;
        numero /= 10;       
    }

    return res;
}

void sol(){
    int n,k;
    cin>>n>>k;

    map<int,int> aux;
    forn(i,n){
        int x;
        cin>>x;
        aux[x]++;
    }

    unordered_map<int,int> sumas;

    while(k>=0){
        auto it = prev(aux.end());
        ii curr = *it;
        int nvo,rep;

        if(k-curr.second <= 0){
            break;
        }
        else{
            rep = curr.second;
            k-=rep;
            if(!sumas.count(curr.first)){
                sumas[curr.first] = sum(curr.first);
            }
            nvo = curr.first-sumas[curr.first];

            
            aux.erase(it);
            aux[nvo]+= rep;
        }
    }

    if(!sumas.count((*prev(aux.end())).first)){
        sumas[(*prev(aux.end())).first] = sum((*prev(aux.end())).first);
    }
    //nvo = curr.first-sumas[curr.first];

    
    debln( sumas[( (*prev(aux.end())).first ) ]);

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