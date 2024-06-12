#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int l1 = i;
        int l2 = n - (i * 2);
        l2 /= 2;

        if (l1 * 2 + l2 * 2 > n)   continue;
        mx = max(mx, l2 * l1);
    }

    cout << mx;
}


// 2 * 2 * 3