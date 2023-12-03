#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minChangesToAP(vector<int>& b, int n) {
    if (n <= 2) return 0;

    const int INF = 1e9;
    int min_changes = INF;

    // Try all combinations for the first two elements
    for (int first : {-1, 0, 1}) {
        for (int second : {-1, 0, 1}) {
            int changes = 0;
            if (first != 0) changes++;
            if (second != 0) changes++;

            int start = b[0] + first;
            int next = b[1] + second;
            int d = next - start;
            bool valid = true;

            // Check if rest of the elements fit the progression
            for (int i = 2; i < n; ++i) {
                int expected = start + i * d;
                if (b[i] == expected || b[i] - 1 == expected || b[i] + 1 == expected) {
                    if (b[i] != expected) changes++;
                } else {
                    valid = false;
                    break;
                }
            }

            if (valid) min_changes = min(min_changes, changes);
        }
    }

    return min_changes == INF ? -1 : min_changes;
}

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int result = minChangesToAP(b, n);
    cout << result << endl;

    return 0;
}
