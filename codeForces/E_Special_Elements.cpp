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
    int n;cin>>n;
    
    int a[n+1];
    a[0] = 0;
    unordered_map<int, pair<int,bool>> ok;

    fore(i,1,n){
        cin>>a[i];
        if(ok.count(a[i]))  ok[ a[i] ].first++;
        else                ok[ a[i] ] = {1,false};
        a[i] = a[i] + a[i-1];
    }    

    fore(i,2,n){
        int curr = 0;
        fore(j,1,n+1-i){
            curr = a[j+i-1] - a[j-1];
            if(ok.count(curr)){
                ok[curr].second = true;
            }
            //cout << curr << " ";
            //cout << j << " ";
        }
        //debug("");
    }


    int res = 0;
    for(auto x : ok){
        if(x.second.second) res+=x.second.first;
    }

    debug(res);
    
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}