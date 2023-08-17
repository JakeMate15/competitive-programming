#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debugln(a)      cout << a << "\n"
#define debug(a)        cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9+7;
const int mx = 1e9;

void sol(){
	string s;cin>>s;
    map<char,int> a;
    for(char c: s)  
        a[c]++;


    int flag = false;
    deque<pair<int,char>> aux;
    pair<int,char> nc;
    for(auto x: a){
        if(x.second%2==1){
            if(flag){
                debugln("NO SOLUTION");
                return;
            }
            else{
                flag = true;
            }
            aux.push_front({x.second,x.first});
        }
        else{
            aux.push_back({x.second,x.first});
        }
        
    }

    deque<char> d;
    for(auto x: aux){
        if(x.first&1){
            forn(i,x.first)
                d.push_front(x.second);
            
            continue;
        }

        forn(i,x.first/2)   d.push_front(x.second);
        forn(i,x.first/2)   d.push_back(x.second);
    }

    for(auto x: d)  cout << x;
    debugln("");
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	//cin>>t;
	while(t--){
		sol();
	}

	return 0;
}