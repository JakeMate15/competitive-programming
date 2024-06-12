#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    vector<long long> count(N + 1, 0);
    vector<long long> prefix(N + 1, 0);

    // Rellenar las combinaciones posibles para cada lado a
    for (int a = 1; a <= N; ++a) {
        for (int b = a; b <= N; ++b) {
            if (a + b <= N) {
                count[a + b]++;
            }
        }
    }

    // Calcular las sumas acumulativas
    for (int i = 1; i <= N; ++i) {
        prefix[i] = (prefix[i - 1] + count[i]) % MOD;
    }

    long long result = 0;

    // Contar todos los triángulos válidos
    for (int a = 1; a <= N / 3; ++a) {
        for (int b = a; b <= (N - a) / 2; ++b) {
            int c_min = b + 1;
            int c_max = min(N - a - b, a + b - 1);

            if (c_min <= c_max) {
                result = (result + (prefix[c_max] - prefix[c_min - 1] + MOD) % MOD) % MOD;
            }
        }
    }

    cout << result << endl;
    return 0;
}
