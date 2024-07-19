#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(v)          v.begin(), v.end()
#define sz(a)           (int)a.size()

void sol() {
    int n;
    cin >> n;

    vector<string> letras = {"***************", "*.**.**..*.**..", "*******..*.****", "*.**.**..*.**..", "*.*************"};
    map<char, ii> aux = {
        {'A', make_pair(0, 2)},
        {'B', make_pair(3, 5)},
        {'C', make_pair(6, 8)},
        {'D', make_pair(9, 11)},
        {'E', make_pair(12, 14)}
    };

    string s;
    cin >> s;

    for (int i = 0; i < 5; i++) {
        for (auto &x: s) {
            for (int j = aux[x].first; j <= aux[x].second; j++) {
                cout << letras[i][j];
            }
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