#include <bits/stdc++.h>
using namespace std;

map<int64_t, int64_t> ans;
int64_t ask (int64_t p) {
    if (ans.count(p)) {
        return ans[p];
    }

    cout << "buf[" << p << "]\n";
    int64_t r;
    cin >> r;

    ans[p] = r;

    return r;
} 

int main () {
    int64_t lo = 1, hi = 4;

    while (ask(hi-1)) {
        hi <<= 1;
    }

    // cerr << hi << "\n";
    while (lo + 1 < hi) {
        int64_t mid = (lo + hi) / 2;
        if (ask(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << "strlen(buf) = " << hi << "\n";

    return 0;
}