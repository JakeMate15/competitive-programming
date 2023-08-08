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
#define sz(a)   (int)a.size()

void sol(){
        int n;
        int num;
        string operacion;
        priority_queue <int, vector<int>, greater<int>>  pq;

        vector<string> res;

        cin>>n;
        while(n--){
                cin>>operacion;

                if(operacion=="insert"){
                        cin>>num;
                        res.push_back("insert " + to_string(num));
                        //cout << "insert " << num << "\n";
                        pq.push(num);
                }
                else if(operacion=="removeMin"){
                        //Cola vacia
                        if(pq.empty()){
                                res.push_back("insert 0");
                                
                        }
                        else{
                                pq.pop();
                        }
                        
                        res.push_back("removeMin");
                }
                else{   
                        cin>>num;

                        while(!pq.empty() && pq.top()>num){
                                pq.pop();
                                res.push_back("removeMin");
                        }

                        if(pq.empty() || pq.top()<=num){
                                pq.push(num);
                                res.push_back("insert " + to_string(num));
                        }

                        res.push_back("getMin " + to_string(num));


                }
        }

        debug(sz(res));
        for(auto x: res){
                debug(x);
        }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}
