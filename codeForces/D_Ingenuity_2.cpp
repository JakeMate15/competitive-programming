#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, char> inv{{'N', 'S'}, {'S', 'N'}, {'E', 'W'}, {'W', 'E'}};

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'N') y += 1;
        else if (c == 'S') y -= 1;
        else if (c == 'E') x += 1;
        else if (c == 'W') x -= 1;
    }

    if (x % 2 != 0 || y % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    vector<char> ans(n, 'R');
    if (x == 0 && y == 0) {
        if (n == 2) {
            cout << "NO" << endl;
            return;
        }
        int pos = s.find(inv[s[0]]);
        ans[0] = ans[pos] = 'H';
    } else {
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N' && y > 0) {
                y -= 2;
                ans[i] = 'H';
            } else if (s[i] == 'S' && y < 0) {
                y += 2;
                ans[i] = 'H';
            } else if (s[i] == 'E' && x > 0) {
                x -= 2;
                ans[i] = 'H';
            } else if (s[i] == 'W' && x < 0) {
                x += 2;
                ans[i] = 'H';
            }
        }
    }

    for (char c : ans) {
        cout << c;
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