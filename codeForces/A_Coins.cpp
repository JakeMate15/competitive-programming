#include <bits/stdc++.h>
using namespace std;
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
#define fore(i,s,n) forsn(i,s,n)

#define mp make_pair
#define snd second
#define fst first
#define pb push_back

#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define DBG(x) cout<<#x<<" = "<<x<<endl;

template<class x> 
ostream &operator<<(ostream &out, vector<x> v) {
    out << "{";
    for(auto y : v) {
        out << y << " ";
    }
    out << "}";
    return out;
}
typedef long long ll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<int> arr(n);
        iota(ALL(arr), 1);

        DBG(arr);

        if(((n & 1) && k % 2 == 0) || n == 1 && k != 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}