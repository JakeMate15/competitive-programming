#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(v)          v.begin(), v.end()
#define sz(a)           (int)a.size()

void sol() {
    int n;
    cin >> n;

    vector<ii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].first *= -1;
        arr[i].second = i;
    }

    sort(all(arr));

    int q;
    cin >> q;

    while (q--) {
        int k, p;
        cin >> k >> p;

        vector<ii> aux(k);
        for (int i = 0; i < k; i++) {
            aux[i] = {arr[i].second, arr[i].first};
        }

        sort(all(aux));

        cout << -aux[p - 1].second << "\n";
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
