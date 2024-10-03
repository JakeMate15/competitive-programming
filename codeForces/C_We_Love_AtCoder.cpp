#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        long long K;
        cin >> N >> M >> K;

        if (N == 1) {
            if (K >= 1 && K <= M) {
                if (M == 1 && K == 1) {
                    cout << "N" << endl;
                } else {
                    cout << "S ";
                    if (K != 1) {
                        cout << 1 << endl;
                    } else {
                        cout << 2 << endl;
                    }
                }
            } else {
                cout << "S " << 1 << endl;
            }
        } else if (M <= 2) {
            if (K >= 1 && K <= (long long)N * M) {
                cout << "N" << endl;
            } else {
                cout << "S";
                for (int i = 0; i < N; ++i) {
                    cout << " " << 1;
                }
                cout << endl;
            }
        } else {
            cout << "S";
            for (int i = 0; i < N; ++i) {
                cout << " " << 1 + (i % 2);
            }
            cout << endl;
        }
    }
    return 0;
}
