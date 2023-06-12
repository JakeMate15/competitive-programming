#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

void sol(){
    int n;cin>>n;
    int a[n];
    forn(i,n)   cin>>a[i];

    vector<int> aux;
    aux.push_back(a[0]);
    string res = "1";

    bool creciente = true;
    forr(i,1,n){
        if(a[i]>=aux.back() && a[i]<=aux[0]){
            aux.push_back(a[i]);
            res+="1";
        }
        else if(a[i]>=aux.back() && creciente){
            aux.push_back(a[i]);
            res+="1";
        }
        else if(a[i]<=a[0] && creciente){
            if(a[i]<a[0])   creciente=false;
            aux.push_back(a[i]);
            res+="1";
        }
        else{
            res+="0";
        }

        if( aux.back() < aux[aux.size()-2] )    creciente = false;
    }
    

    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}