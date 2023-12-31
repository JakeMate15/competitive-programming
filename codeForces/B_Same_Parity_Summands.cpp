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
    int n, k;
    cin >> n >> k;
    if(n >= 2 * k && n % 2 == 0) {
        cout << "YES\n";
        for(int i = 0; i < k - 1; i++)
            cout << "2 ";
        cout << n - 2*(k - 1) << '\n';
        return;
    }
    if(n >= k && n % 2 == k % 2) {
        cout << "YES\n";
        for(int i = 0; i < k - 1; i++)
            cout << "1 ";
        cout << n - k + 1 << '\n';
        return;
    }
    cout << "NO\n";
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