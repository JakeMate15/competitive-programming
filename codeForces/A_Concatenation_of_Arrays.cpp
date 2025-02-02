#include <bits/stdc++.h> 
using namespace std;

void Main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<int, int> p1, pair<int, int> p2) {
        int a = p1.first + p1.second, b = p2.first + p2.second;
        // return true if no swap, false if swap
        return a < b;
        
    });

    for (int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) Main();
    return 0;
}