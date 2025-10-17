#include<bits/stdc++.h>
using namespace std;
 
const int INF = 1E9;

void sol () {
    int64_t n;
    cin >> n;

    int64_t p = 10;
    vector<int64_t> ans;
    for (int i = 1; i <= 18; i++) {
        int64_t x = n / (1 + p);
        if (n == x * (1 + p)) {
            ans.push_back(x);
        }
        p *= 10;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
 
    while(t--) {
        sol();
    }
 
    return 0;
}