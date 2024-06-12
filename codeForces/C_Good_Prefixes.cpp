#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Función que cuenta el número de prefijos buenos en un array
int count_good_prefixes(const vector<int>& a) {
    int n = a.size();
    unordered_set<long long> prefix_sums;
    long long current_sum = 0;
    int good_prefixes = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += a[i];
        if (current_sum == a[i] || prefix_sums.count(current_sum - a[i])) {
            ++good_prefixes;
        }
        prefix_sums.insert(current_sum);
    }

    return good_prefixes;
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

        // Contar y mostrar el número de prefijos buenos
        cout << count_good_prefixes(a) << endl;
    }

    return 0;
}
