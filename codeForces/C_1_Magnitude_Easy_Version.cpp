#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void sol() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) 
        cin >> x;

    ll mn = 0, s = 0;
    for (auto x: a) {
        s += x;
        mn = min(mn, s);
    }

    cout << s - 2 * mn << "\n";
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