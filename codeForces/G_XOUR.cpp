#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()

typedef int64_t ll;

void sol() {
    int n;
    cin >> n;
    
    vector<int> arr(n), res(n);
    map<int, vector<int>> pos;
    map<int, multiset<int>> grupos;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        int aux = (arr[i] >> 2);
        pos[aux].push_back(i);
        grupos[aux].insert(arr[i]);
    }

    for (auto [k, mst]: grupos) {
        int i = 0;
        for (auto v: mst) {
            res[pos[k][i]] = v;
            i++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
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