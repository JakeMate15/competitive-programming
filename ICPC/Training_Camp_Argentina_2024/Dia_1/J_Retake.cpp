#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;

const int mx = 5e6 + 5;

int main () {
    int n;
    cin >> n;

    vector<vector<ii>> arr(mx, vector<ii>());
    for (int i = 1; i <= n; i++) {
        int t, c;
        cin >> t >> c;

        arr[t].emplace_back(c, i);
    }

    priority_queue<ii> pq;
    int d = 0;
    vector<int> res(n + 5);
    for (int i = 1; i <= mx; i++) {
        if (sz(arr[i]) == 0 && pq.empty()) 
            continue;

        for (auto [a, b]: arr[i]) {
            pq.emplace(a - d, b);
            // cerr << b << "\n";
        }
        d++;
        res[pq.top().second] = i;
        pq.pop();
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
    }

    return 0;
}