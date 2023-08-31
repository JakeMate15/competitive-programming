#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

int s;
const int mx = 5e5+5;
int qt[mx],res[mx],a[mx];
bool ta[mx];
                
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.first.first / s == b.first.first / s){
                if((a.first.first / s) & 1)
                        return a.first.second > b.first.second;
                return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
}

void sol(){
        int n,q;
        cin>>n;
        forn(i,n){
                cin>>a[i];
        }

        vector<pair<pair<int,int>, int>> qry;
        cin>>q;
        s = sqrt(n);
        forn(i,q){
                int l, r;
                cin>>l>>r;
                l--;
                r--;
                qry.push_back({{l, r}, i});
        }
        sort(all(qry), cmp);
 
        int l = qry[0].first.first;
        int r = qry[0].first.first;
        qt[a[l]] = 1;

        vector<int> ans;
        ans.push_back(a[l]);

        forn(i,q){
                int al = qry[i].first.first;
                int ar = qry[i].first.second;
                int id = qry[i].second;
                while(r < ar){
                        r++;
                        qt[a[r]]++;
                        if(qt[a[r]] == 1 && !ta[a[r]]){
                                ans.push_back(a[r]);
                                ta[a[r]] = 1;
                        }
                }
                while(r > ar){
                        qt[a[r]]--;
                        if(qt[a[r]] == 1 && !ta[a[r]]){
                                ans.push_back(a[r]);
                                ta[a[r]] = 1;
                        }
                        r--;
                }
                while(l < al){
                        qt[a[l]]--;
                        if(qt[a[l]] == 1 && !ta[a[l]]){
                                ans.push_back(a[l]);
                                ta[a[l]] = 1;
                        }
                        l++;
                }
                while(l > al){
                        l--;
                        qt[a[l]]++;
                        if(qt[a[l]] == 1 && !ta[a[l]]){
                                ans.push_back(a[l]);
                                ta[a[l]] = 1;
                        }
                }
                while(ans.size() && qt[ans.back()] != 1){
                        ta[ans.back()] = 0;
                        ans.pop_back();
                }
                if(ans.size()){
                        res[id] = ans.back();
                }
        }
                
        forn(i,q){
                debug(res[i]);
        }

}

int main(){IO
        int t=1;
        //cin>>t;
        while(t--)  sol();
}