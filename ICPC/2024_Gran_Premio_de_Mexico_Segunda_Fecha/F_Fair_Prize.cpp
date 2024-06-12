#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, x;
    cin >> n >> a;
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x <= a)
            res = max(res, x);
    }

    cout << res << "\n";
}   