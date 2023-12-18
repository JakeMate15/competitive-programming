#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << "\n";
    }

    int pos = n - 1;
    while(q--) {
        int d;
        cin >> d;

        int nvo = n - d;
        if(nvo == pos) {
            cout << "-1 -1 -1\n"; 
        }
        else {
            cout << n << " " << pos << " " << nvo << "\n";
            pos = nvo;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}