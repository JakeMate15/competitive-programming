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

void sol(){
    int n,m;
    cin>>n>>m;

    vi a(n);
    vi b(m);

    for(auto &x: a)
        cin>>x;

    for(auto &x: b)
        cin>>x;

    vi res;

    int i=0,j=0;
    while(i<sz(a) && j<(sz(b))){
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[j]);
            j++;
        }
    }

    while(i<n){
        res.push_back(a[i]);
        i++;
    }

    while(j<m){
        res.push_back(b[j]);
        j++;
    }

    for(auto &x: res)
        cout << x << " ";


}

int main(){IO
	int t=1;
	//cin>>t;
	while(t--)  sol();
}