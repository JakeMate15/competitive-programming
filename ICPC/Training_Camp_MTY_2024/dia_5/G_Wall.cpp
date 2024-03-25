#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

vector<string> aux = {"111","110","101","100","011","010","001","000"};

void sol() {
    int a, b;
    cin >> a >> b;

    reverse(all(aux));

    set<string> permitidos;
    for (int i = 0; i < 8; i++) {
        if (a & (1 << i)) {
            permitidos.insert(aux[i]);
        }
    }

    string s;
    cin >> s;

    int n = sz(s);
    vector<vector<int>> m(b + 1, vector<int>(n + 2));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            m[0][i + 1] = 1;
        }
    }

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= n; j++) {
            string aaa = "";
            aaa += (m[i - 1][j - 1] ? "1" : "0");
            aaa += (m[i - 1][j] ? "1" : "0");
            aaa += (m[i - 1][j + 1] ? "1" : "0");

            if (permitidos.count(aaa)) {
                m[i][j] = 1;
            } 
        }
    }

    vector<string> res;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (m[i][j] ? 'X' : '.');
        }
        cout << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}