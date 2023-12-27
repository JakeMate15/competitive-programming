#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

/*

1 2 3 4 5 6
1 6
2 5
3 4
4 3
5 2
6 1

2 3 5 7 11 13 17 19

*/

void sol(){
    int n;
    cin >> n;

    if(n <= 2) {
        for(int i = n; i >= 1; i--) {
            cout << i << " ";
        }
        nl;
        return;
    }

    vector<int> res(n, 0);
    res[n / 2] = 1, res[0] = 2, res[n - 1] = 3;
    int cnt = 4;
    for(auto &x: res) {
        if(x == 0) {
            x = cnt++;
        }
        cout << x << ' ';
    }
    nl;
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