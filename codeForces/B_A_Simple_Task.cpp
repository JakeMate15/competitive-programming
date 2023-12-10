#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string S;
    cin >> S;

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        // Adjust indices for 0-based indexing
        i--; j--;

        // Extract and sort the substring
        string sub = S.substr(i, j - i + 1);
        if (k == 1) {
            sort(sub.begin(), sub.end()); // Sort in non-decreasing order
        } else {
            sort(sub.rbegin(), sub.rend()); // Sort in non-increasing order
        }

        // Replace the original substring with the sorted one
        S.replace(i, j - i + 1, sub);
    }

    // Output the final string
    cout << S << endl;

    return 0;
}
