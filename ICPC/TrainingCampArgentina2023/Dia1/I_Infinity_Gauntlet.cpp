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


void sol(){
        map<string,pair<string,int>> a;
        a["purple"] = {"Power",0};
        a["green"] = {"Time",0};
        a["blue"] = {"Space",0};
        a["orange"] = {"Soul",0};
        a["red"] = {"Reality",0};
        a["yellow"] = {"Mind",0};

        int n;
        cin>>n;
        forn(i,n){
                string s;
                cin>>s;
                
                a[s].second++;

        }

        vector<string> res;
        for(auto x: a){
                if(x.second.second<=0){
                        res.push_back(x.second.first);
                }
        }

        debug(sz(res));
        for(string x: res){
                debug(x);
        }

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}