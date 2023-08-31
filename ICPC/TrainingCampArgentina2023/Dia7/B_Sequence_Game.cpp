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
        int n;
        cin>>n;

        vi a(n);
        for(auto &x: a){
                cin>>x;
        }

        
        if(n==1){
                debug(1);
                debug(a[0]);
                return;
        }

        vi ans;
        ans.push_back(a[0]);
        forr(i,1,n){
                if(ans.back() == a[i] && i==n-1){
                        //ans.push_back(a[i]);
                }
                else{
                        if(a[i-1]==a[i]){
                                if((int)ans.size()-2>=0){
                                        if(ans[ans.size()-2] == ans.back()){
                                                continue;
                                        }
                                }

                                ans.push_back(a[i]);
                                continue;
                        }
                        else{
                                ans.push_back(ans.back()-1);
                                if(ans.back()==0){
                                        ans[ans.size()-1] = a[i];
                                }
                                ans.push_back(a[i]);
                        }
                }
        }

        debug(ans.size());
        for(auto x: ans){
                cout << x << " ";
        }

        debug("");

}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}

/*

*/