#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 400005;

int t, n;
char s[MAX_N];
bool assigned[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s + 1;

        vector<int> visits;
        for (int i = n; i >= 1; --i) {
            if (s[i] == '1') {
                visits.push_back(i);
            }
        }

        memset(assigned, 0, (n + 2) * sizeof(bool));

        long long total_cost = 0;
        long long total_discount = 0;

        // Total cost is sum of costs of all figures
        total_cost = 1LL * n * (n + 1) / 2;

        int expensive_idx = n; // Start from the most expensive figure
        int cheap_idx = 1;     // Start from the cheapest figure

        for (int day : visits) {
            vector<int> available_figures;
            // Collect unassigned figures available on this day
            for (int i = day; i >= 1; --i) {
                if (!assigned[i]) {
                    available_figures.push_back(i);
                }
            }

            // Assign figures in pairs to get the discount
            while (available_figures.size() >= 2) {
                int idx1 = available_figures.back(); available_figures.pop_back();
                int idx2 = available_figures.back(); available_figures.pop_back();
                assigned[idx1] = assigned[idx2] = true;
                total_discount += idx1; // Add the cost of the most expensive figure
            }

            // If one figure is left, we may or may not get a discount
            if (available_figures.size() == 1) {
                int idx = available_figures.back(); available_figures.pop_back();
                assigned[idx] = true;
                // No discount since only one figure is bought
            }
        }

        // Assign remaining unassigned figures
        for (int i = 1; i <= n; ++i) {
            if (!assigned[i]) {
                // Figures can always be bought on day n since s_n == '1'
                assigned[i] = true;
                // No discount for these figures
            }
        }

        long long final_cost = total_cost - total_discount;
        cout << final_cost << '\n';
    }

    return 0;
}
