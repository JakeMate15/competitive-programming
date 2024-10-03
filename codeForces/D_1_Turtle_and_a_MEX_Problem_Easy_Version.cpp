#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, k;
    cin >> n >> k;

    auto gaus = [] (int64_t n) -> int64_t {
        if (n <= 0)
            return 0LL;
        return n * (n + 1) / 2;
    };
    
    int mex = 0;
    for (int i = 0; i < n; i++) {
        int l, x;
        cin >> l;

        unordered_set<int> st;
        for (int j = 0; j < l; j++) {
            cin >> x;
            st.insert(x);
        }

        int cmex = 0;
        bool f = true;
        while (st.count(cmex) || f) {
            f &= st.count(cmex);
            cmex++;
        }

        mex = max(mex, cmex);
    }

    int64_t res = 0;
    if (k > mex) {
        res += gaus(k) - gaus(mex);
        res += 1LL * mex * (mex + 1);
    } else {
        res += 1LL * mex * (k + 1);
    }

    cout << res << "\n";
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