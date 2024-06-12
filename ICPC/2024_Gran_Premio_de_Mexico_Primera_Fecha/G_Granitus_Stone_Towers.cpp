#include<bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int win = 0;
    for (int i = n; i >= 1; i--) {
        int v = a[i] - a[i - 1];
        if (v > 0) {
            if (win == 0) {
                win = 1;
            } else if (v == 1) {
                win = 0;
            }
        }
    }
    
    cout << (win ? "Alicius" : "Bobius") << "\n";

    return 0;
}