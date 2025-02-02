#include<bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int64_t> bit;

    BIT(const vector<int>& arr) {
        n = arr.size() + 1;
        bit.assign(n, 0);
        for (int i = 0; i < arr.size(); ++i) {
            add(i + 1, arr[i]);
        }
    }

    void add(int idx, int64_t val) {
        for (; idx < n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int64_t sum(int idx) const {
        int64_t res = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

    int64_t sum(int l, int r) const {
        return sum(r) - sum(l - 1);
    }

    void set_val(int idx, int new_val) {
        int current_val = sum(idx, idx);
        int64_t diff = static_cast<int64_t>(new_val) - static_cast<int64_t>(current_val);
        add(idx, diff);
    }
};

void sol () {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    BIT st(arr);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            st.set_val(l, r);
        } else {
            cout << st.sum(l, r) << "\n";
        }
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
