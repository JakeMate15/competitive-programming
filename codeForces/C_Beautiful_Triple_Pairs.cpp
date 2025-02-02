#include <bits/stdc++.h>
using namespace std;

struct Triplet {
    int a, b, c;

    Triplet(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

    bool operator==(const Triplet& other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    bool operator<(const Triplet& other) const {
        if (a == other.a) {
            if ()
        }
    }
};

struct TripletHash {
    size_t operator()(const Triplet& t) const {
        return ((size_t)t.a * 1000003) ^ ((size_t)t.b * 1000033) ^ ((size_t)t.c * 1000037);
    }
};

void sol () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    int64_t res = 0;
    map<Triplet, int, TripletHash> cnt;
    for (int i = 0; i < n - 2; i++) {
        int a = arr[i], b = arr[i + 1], c = arr[i + 2], z = -1;
        Triplet t1(z, b, c);
        Triplet t2(a, z, c);
        Triplet t3(a, b, z);
        Triplet t4(a, b, c);

        res += cnt[t1];
        res += cnt[t2];
        res += cnt[t3];

        res -= 3 * cnt[t4];

        cnt[t4]++;
        cnt[t1]++;
        cnt[t2]++;
        cnt[t3]++;
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
