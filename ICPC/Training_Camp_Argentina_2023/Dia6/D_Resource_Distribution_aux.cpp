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

bool val(int n, int a, int b, vector<pair<int,int>>& v, bool fl) {
        int actual = 0;
        int i;
        vi vb;
        bool flb = false;
        for (i = 0; i < n; i++) {
                actual = (i + 1) * v[i].first;
                vb.push_back(v[i].second);
                if (actual >= b) {
                        flb = true;
                        break;
                }
        }
        int pos = i;
        vi va;
        bool fla = false;
        for (i++; i < n; i++) {
                actual = (i - pos) * v[i].first;
                va.push_back(v[i].second);
                if (actual >= a) {
                        fla = true;
                        break;
                }
        }
        if (flb == true && fla == true) {
                YES;
                if (fl) {
                        swap(va, vb);
                }
                cout << va.size() << " " << vb.size() << endl;
                for (int i = 0; i < va.size(); i++) {
                        cout << va[i] + 1 << " ";
                }
                cout << endl;
                for (int i = 0; i < vb.size(); i++) {
                        cout << vb[i] + 1 << " ";
                }
                cout << endl;
                return true;
        }
        else {
                return false;
        }
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
        if (!val(n, a, b, arr, false)) {
                if (!val(n, b, a, arr, true)) {
                        NO;
                }
        }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}