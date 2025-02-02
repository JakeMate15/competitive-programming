#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    string num;
    int k;
    cin >> num >> k;

    string num2 = num;
    int k2 = k;

    // cerr << num << "\n";
    for (int i = 0; i < sz(num) - 1 && k > 0; i++) {
        int mx = i + 1;
        for (int j = i + 1; j < sz(num); j++) {
            if (num[mx] < num[j]) {
                mx = j;
            }
        }

        if (num[mx] > num[i]) {
            swap(num[mx], num[i]);
            k--;
        }
    }

    // cerr << num << "\n";
    for (int i = 0; i < sz(num) - 1 && k2 > 0; i++) {
        // cerr << "=====================\n";
        // cerr << num << "\n";
        int mx = sz(num) - 1;
        for (int j = sz(num) - 1; j >= i; j--) {
            if (num2[j] > num2[mx]) {
                mx = j;
            }
        }

        // cerr << num[mx] << " " << num[i] << "\n";
        if (num2[mx] > num2[i]) {
            swap(num2[mx], num2[i]);
            k2--;
        }
        // cerr << num << "\n";
    }

    cout << max(num, num2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}