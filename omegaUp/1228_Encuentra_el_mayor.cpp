#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    short int n;
    cin >> n;

    short int res = 0;
    for(short int i = 0; i < n; i++) {
        short int a;
        cin >> a;
        res = max(a, res);
    }

    cout << res << "\n";

    return 0;
}