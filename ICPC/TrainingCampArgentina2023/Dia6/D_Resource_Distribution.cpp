#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.rbegin(),v.rend()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "Yes\n"
#define NO          cout << "No\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

void imp(bool bandera, vi res, vi res2){
        YES;
        if (bandera) {
                swap(res2, res);
        }
        cout << sz(res2) << " " << sz(res) << endl;
        forn(i,sz(res2))cout << res2[i] + 1 << " ";
        debug("");
        forn(i,sz(res)) cout << res[i] + 1 << " ";
}

void sol(){
        int n,a,b;
        cin>>n>>a>>b;

        vector<pair<int,int>> arr(n);
        forn(i,n){
                cin>>arr[i].first;
                arr[i].second = i;
        }

        sort(all(arr));


        int actual = 0;
        int i;
        vi res;
        bool bandera = false,banderab = false;
        for (i = 0; i < n; i++) {
                actual = (i + 1) * arr[i].first;
                res.push_back(arr[i].second);
                if (actual >= b) {
                        banderab = true;
                        break;
                }
        }
        int pos = i;
        vi res2;
        bool banderaa = false;
        for (i++; i < n; i++) {
                actual = (i - pos) * arr[i].first;
                res2.push_back(arr[i].second);
                if (actual >= a) {
                        banderaa = true;
                        break;
                }
        }
        if (banderab == true && banderaa == true) {
                imp(bandera,res,res2);
        }
        else {
                swap(a,b);
                actual = 0;
                i = 0;
                res.clear();
                bool bandera = true,banderab = false;
                for (i = 0; i < n; i++) {
                        actual = (i + 1) * arr[i].first;
                        res.push_back(arr[i].second);
                        if (actual >= b) {
                                banderab = true;
                                break;
                        }
                }
                pos = i;
                res2.clear();
                banderaa = false;
                for (i++; i < n; i++) {
                        actual = (i - pos) * arr[i].first;
                        res2.push_back(arr[i].second);
                        if (actual >= a) {
                                banderaa = true;
                                break;
                        }
                }
                if (banderab == true && banderaa == true) {
                        imp(bandera,res,res2);
                }
                else {
                        NO;
                }
        }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}