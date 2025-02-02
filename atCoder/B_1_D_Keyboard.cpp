#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> x(26);
    for (int i = 0; i < 26; ++i)
        x[s[i] - 'A'] = i;
    int ans = 0;
    for (int i = 0; i < 25; ++i)
        ans += abs(x[i] - x[i + 1]);
    cout << ans << endl;
}