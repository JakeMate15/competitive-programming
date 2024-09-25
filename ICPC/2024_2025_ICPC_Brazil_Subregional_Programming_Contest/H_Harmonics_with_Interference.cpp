#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> s(2);
    cin >> s[0] >> s[1];

    vector<ii> as;
    for (int i = 0; i < 2; i++) {
        reverse(s[i].begin(), s[i].end());
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == '*') {
                as.emplace_back(i, j);
            }
        }
    }

    for (int msk = 0; msk < (1 << as.size()); msk++) {
        vector<string> nS = s;
        int idx = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < nS[i].size(); j++) {
                if (nS[i][j] == '*') {
                    char aux = (msk & (1 << idx)) ? '1' : '0';
                    nS[i][j] = aux;
                    idx++;
                }
            }
        }

        ll ss = 0;
        for (int j = 0; j < nS[1].size(); j++) {
            if (nS[1][j] == '1') {
                ss |= (1LL << j);
            }
        }

        if (ss == 0) {
            continue;
        }

        ll pot = 1, r = 0;
        for (int j = 0; j < nS[0].size(); j++) {
            if (nS[0][j] == '1') {
                r = (r + pot) % ss;
            }
            pot = (pot * 2) % ss;
        }

        if (r == 0) {
            reverse(nS[0].begin(), nS[0].end());
            cout << nS[0] << "\n";
            break;
        }
    }

    return 0;
}