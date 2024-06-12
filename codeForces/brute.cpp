#include <iostream>
#include <vector>

using namespace std;

bool isBeautiful(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool allDivisible = true;
            for (int k = 0; k < n; ++k) {
                if (a[k] % a[i] != 0 && a[k] % a[j] != 0) {
                    allDivisible = false;
                    break;
                }
            }
            if (allDivisible) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (isBeautiful(a)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
