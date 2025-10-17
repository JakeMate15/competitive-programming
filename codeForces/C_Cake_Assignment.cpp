#include<bits/stdc++.h>
using namespace std;

void sol () {
    int64_t k, x;
    cin >> k >> x;

    vector<int> arr; 
    int64_t a = x, b = (1LL << (k + 1)) - x;
    while (a != b) {
        if (a < b) {
            arr.push_back(1);
            b -= a;
            a <<= 1;
        } else { 
            arr.push_back(2);
            a -= b;
            b <<= 1;
        }
    }

    cout << arr.size() << "\n";
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
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