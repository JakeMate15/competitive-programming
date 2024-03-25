#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        // Calculate the total number of chips
        int totalChips = N * K;
        
        // Check if N is a multiple of (K + 1)
        if (N % (K + 1) == 0) {
            cout << "Omda" << endl;
        } else {
            cout << "Teemo" << endl;
        }
    }
    return 0;
}
