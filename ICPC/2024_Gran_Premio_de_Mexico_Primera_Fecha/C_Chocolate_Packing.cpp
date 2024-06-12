#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a(3), b(3);
    for (auto &x: a)    
        cin >> x;
    for (auto &x: b)    
        cin >> x;

    sort(all(b));

    int res = 0;
    do {
        int l = a[0] / b[0], w = a[1] / b[1], h = a[2] / b[2];
        res = max(res, l * w * h); 

    } while (next_permutation(all(b)));

    cout << res;

    return 0;
}