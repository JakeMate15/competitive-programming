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

    vector<int> a(105), ult(105);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
        ult[x] = i + 1;
    }

    for(int i = 1; i <= 100; i++) {
        if(a[i] == 1) {
            cout << ult[i] << "\n";
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}