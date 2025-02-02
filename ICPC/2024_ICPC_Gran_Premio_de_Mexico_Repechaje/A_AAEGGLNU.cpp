#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<pair<string, string>> arr(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string ordS = s;
        sort(all(ordS));
        arr[i] = {ordS, s};
    }

    sort(all(arr));

    int q;
    cin >> q;
    
    while (q--) {
        string s;
        cin >> s;

        string ordS = s;
        sort(all(ordS));

        auto it = upper_bound(all(arr), make_pair(ordS, s));
        cout << (it - arr.begin()) << "\n";
    }

    return 0;
}
