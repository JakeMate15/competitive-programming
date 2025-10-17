#include<bits/stdc++.h>
using namespace std;

void sol () {
    int n, x;
    cin >> n >> x;
 
    bool valid = true;
    vector<int> arr(n);
    int mex = 0, msk = 0;
    for (int i = 0; i < n; i++) {
        if (valid) {
            for (int j = 0; j <= 30; j++) {
                if ((i & ((1 << j))) > 0 && (x & ((1 << j))) == 0) {
                    valid = false;
                    break;
                }
            }
        } 
 
        arr[i] = (valid ? i : x);
        msk |= arr[i];
    }
 
    if (msk != x) {
        arr[n - 1] = x;
    }
    
    msk = 0;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " \n"[i == n - 1];
        msk |= arr[i];
    }
    assert(msk == x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}