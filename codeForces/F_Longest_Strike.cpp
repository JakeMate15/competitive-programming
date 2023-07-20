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
    int n,k;
    cin>>n>>k;

    vi a(n);
    map<int,int> rep;
    forn(i,n){
        cin>>a[i];
        if(rep.count(a[i])) rep[a[i]]++;
        else                rep[a[i]]=1;
    }

    a.clear();

    vi b;
    for(auto x: rep){
        if(x.second>=k) b.push_back(x.first);
    }

    rep.clear();

    if(!sz(b)){
        debug(-1);
        return;
    }

    b.push_back(-50);

    /*
    11 13 14 -50
    1 2 3 5 6 -50
    -1
    1 2 3 4 -50
    */
    
    int mx, l, r, ant;
    int curr, currL, currR;

    mx = curr = 1;
    l = r = currL = currR = ant = b[0];

    
    forr(i,1,sz(b)+1){
        //cout << l << " " << r << "\n";
        //cout << currL << " " << currR << "\n";
        //cout << ant << " " << b[i] << "\n";

        if( b[i]==(ant+1) ){
            //debug("verdadero");
            currR = b[i];
            curr++;
            ant = b[i];
        }
        else{
            //cout << "falso " << curr << " " << mx << "\n";
            if(curr>mx){
                //cout << "Es mayor " << "\n";
                l = currL;
                r = currR;
                mx = curr;
            }

            currL = b[i];
            currR = b[i];
            curr = 1;
            ant = b[i];
        }
        //debug("");
        
    }

    cout << l << " " << r << "\n";
    

}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}