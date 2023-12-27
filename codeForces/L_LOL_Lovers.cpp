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
    int n;
    string s;
    cin >> n >> s;

    int l1 = 0, o1 = 0, l2 = 0, o2 = 0;
    for(auto x: s) {
        l1 += x == 'L';
        o1 += x == 'O';
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            l1--;
            l2++;
        }
        else {
            o1--;
            o2++;
        }

        if(l1 != l2 && o1 != o2 && (l2 | o2) && (l1 | o1)) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}