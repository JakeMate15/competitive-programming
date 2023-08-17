#include<bits/stdc++.h>

int main() {
    using namespace std;

    unsigned N, M;
    cin >> N >> M;

    vector<tuple<double, unsigned, vector<unsigned>>> roulette(N);
    for (auto&&[C, P, S] : roulette) {
        cin >> C >> P;
        S = vector<unsigned>(P);
        for (auto &&s : S)cin >> s;
    }

    // Tweak to avoid 0 points
    for (auto&&[C, P, S] : roulette) {
        C *= P;
        erase(S, 0);
        P = size(S);
        C /= P;
    }

    vector<double> e(M, 10000 * M); // e[i] := expected amount of money starting from i points
    for (const auto i : ranges::views::iota(0U, M) | ranges::views::reverse) // compute in descending order of i
        for (const auto&[C, P, S] : roulette) {
            double expected = 0;
            for (const auto s : S | ranges::views::filter([i, M](auto s) { return i + s < M; }))
                expected += e[i + s]; // expected amount of money after playing the wheel

            e[i] = min(e[i], C + expected / P); // the minimum C + 1 / P ∑ e[i + s] is the sought e[i]
        }

    cout << e[0] << endl; // e[0] is the answer
    return 0;
}
