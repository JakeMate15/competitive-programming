#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void sol(){
    int n;
    cin>>n;

    vector<ii> segmentos(n);
    forn(i,n){
        int l,r,a,b;
        cin>>l>>r>>a>>b;
        segmentos[i] = {l,b};
    }

    sort(all(segmentos));

    vector<ii> a;
    for(auto &[l,r]: segmentos){
        if(sz(a) && l<=a.back().second){
            a.back().second = max(r,a.back().second);
        }
        else{
            a.emplace_back(l,r);
        }
    }

    int q; 
    cin>>q;
    while(q--){
        int x;
        cin>>x;

        int pos = lower_bound(all(a),make_pair(x+1,0)) - a.begin() - 1;
        if(pos>=0){
            x = max(x,a[pos].second);
        }
        deb(x);
    }
    debln("");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}