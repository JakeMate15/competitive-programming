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
    vector<int> a(20);
    for(int i = 0; i < 3; i++) {
        int x; 
        cin >> x;
        a[x]++;
    }

    for(int i = 0; i < 20; i++) {
        if(a[i] == 1) {
            cout << i << "\n";
            return;
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