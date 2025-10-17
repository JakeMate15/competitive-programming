#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

void sol () {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (auto &x: h) {
        cin >> x;
    }

    int pos = h[k - 1] , Hmax = *max_element(all(h));
    if(pos == Hmax){
        cout << "YES\n";
        return;
    }

    sort(all(h));
    h.erase(unique(all(h)), h.end());
    int pos0 = lower_bound(all(h), pos) - h.begin();
    int pos_max = lower_bound(all(h), Hmax) - h.begin();
    bool ok = true;
    for(int i = pos0 + 1; i <= pos_max; i++){
        if(h[i] - h[i - 1] > pos){
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}