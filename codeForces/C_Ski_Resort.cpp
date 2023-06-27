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

lli fib(int n){
    return (n*(n+1))/2;
}


void sol(){
    int n,dias,temp;
    cin>>n>>dias>>temp;
    lli res = 0, act=0, pre=0;

    forn(i,n){
        int lec;cin>>lec;
        if(lec<=temp){
            if(++act>=dias){
                pre++;
                res+=pre;
            }
        }
        else{
            act = pre = 0;
        }
        

    }

    debug(res);
    //debug("\n\n");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}
