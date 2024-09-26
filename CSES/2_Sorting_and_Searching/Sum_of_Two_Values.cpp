#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        
        if (mp.count(k - x)) {
            cout << i + 1 << " " << mp[k - x] + 1 << "\n";
            return 0;
        }

        mp[x] = i;
    }

    cout << "IMPOSSIBLE\n";
 
    return 0;
}