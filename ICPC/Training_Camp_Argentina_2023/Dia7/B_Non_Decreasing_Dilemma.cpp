#include<bits/stdc++.h>
using namespace std;
 
#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)      	cout << a << "\n"
#define deb(a)        	cout << a << " "
#define pb              push_back
 
typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9+7;

struct nodo{
    ll r,l,res,longitud,rr,LL;

    nodo():l(0),r(0),res(0),longitud(0),rr(0),LL(0){};
    nodo(ll x): l(x),r(x),res(1),longitud(1),rr(1),LL(1){};

    void imprime(){
        deb(l);deb(r);deb(res);deb(longitud);deb(LL);debln(rr);
    }
};

nodo une(nodo a, nodo b){
    nodo aux;

    if(a.longitud == 0) return b;
    if(b.longitud == 0) return a;

    aux.l = a.l;
    aux.r = b.r;
    aux.longitud = a.longitud + b.longitud;
    aux.res = a.res + b.res;

    aux.rr = b.rr;
    if(b.rr == b.longitud && a.r <=b.l)  aux.rr+=a.rr;

    aux.LL = a.LL;
    if(a.LL == a.longitud && a.r<=b.l)  aux.LL+=b.LL;

    if(a.r<=b.l)    aux.res+=(a.rr*b.LL);

    return aux;
}

template<typename T>
struct SegmentStree{
    int n;
    vector<T> st;

    SegmentStree(int n,vector<int> &arr):n(n){
        st.resize(n<<1);
        forn(i,n){
            st[n+i] = arr[i]==0?nodo():nodo(arr[i]);
        }
        for(int i=n-1;i>0;i--){
            st[i] = une(st[i<<1],st[i<<1|1]);
        }
    }

    void update(int i, int value){
        st[i+=n] = nodo(value);
        while(i>>=1){
            st[i] = une(st[i<<1],st[i<<1|1]);
        }
    }

    T query(int l, int r){
        nodo resl = nodo(), resr = nodo();
        for(l+=n,r+=n; l<=r; l>>=1,r>>=1){
            if(l&1)     resl = une(resl,st[l++]);
            if(!(r&1))  resr = une(st[r--],resr);
        }
        return une(resl,resr);
    }

    void imp(){
        int i=0;
        for(auto x: st){
            deb(("Nodo: " + to_string(i) + "\t"));x.imprime();
            i++;
        }
    }
    
};


void sol(){
    int n,q;
    cin>>n>>q;

    int nn = 2;
    while(nn<n){
        nn*=2;
    }

    vector<int> a(nn);
    forn(i,n)
        cin>>a[i];

    SegmentStree<nodo> st(nn,a);
    st.imp();

    while(q--){
        int op;
        cin>>op;

        if(op==1){
            int x,y;
            cin>>x>>y;
            x--;
            st.update(x,y);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            nodo qr = st.query(l,r);
            cout << qr.res << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--){
        sol();
    }

    return 0;
}