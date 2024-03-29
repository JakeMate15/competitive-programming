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
    cin >> n;

    if((n & 1) && n > 1) {
        cout << "-1\n";
    }
    else if(n == 1) {
        cout << "1\n";
    }
    else {
        for(int i = n; i > 1; i -= 2) {
            cout << i << " " << n - i + 1 << " \n"[i == 2];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}