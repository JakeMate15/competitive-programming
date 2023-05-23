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
    int n,k;
    cin>>n>>k;
    vector<int> minus(27,0), mayus(27,0),resto(27,0);
    string s;
    cin>>s;
    for(char c: s){
        if(c<='Z')  mayus[c-'A']++;
        else        minus[c-'a']++;
    }
    
    int posibles = 0;
    forn(i,27){
        if(minus[i]>0 && mayus[i]>0)    posibles+=(min(minus[i],mayus[i]));
    }

    //cout << "Los posibles son " << posibles << endl;

    forn(i,27){
        resto[i] = abs(minus[i]-mayus[i]);
    }

    

    int p = 0;
    forn(i,27){
        p+=(resto[i]/2);
    }

    int res = posibles+min(p,k);

    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}