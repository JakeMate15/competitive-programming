#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = n * m / k, current = 0;
    vector<vector<int>> ans(n, vector<int>(m));
    if(n >= m) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if ((i + j) % 2 == 0)
                    ans[i][j] = current++;

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if ((i + j) % 2 == 1)
                    ans[i][j] = current++;
    } else {
        for (int j = 0; j < m; j++) 
            for (int i = 0; i < n; i++) 
                if ((i + j) % 2 == 0)
                    ans[i][j] = current++;

        for (int j = 0; j < m; j++) 
            for (int i = 0; i < n; i++) 
                if ((i + j) % 2 == 1)
                    ans[i][j] = current++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << ans[i][j] / cnt + 1 << ' ';
        cout << "\n";
    }
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