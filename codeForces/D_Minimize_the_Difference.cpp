#include <iostream>
#include <vector>

using namespace std;

void minimizeDifference() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 1; --i) {
            if (a[i] > a[i + 1]) {
                a[i] = a[i + 1];
            }
        }
        long long result = a[n] - a[1];
        cout << result << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    minimizeDifference();
    return 0;
}
