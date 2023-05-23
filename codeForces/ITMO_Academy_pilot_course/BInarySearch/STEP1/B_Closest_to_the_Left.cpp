//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (k--) {
        int x;
        cin >> x;

        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ++ans << endl;
    }

    return 0;
}
