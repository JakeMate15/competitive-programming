#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the greatest divisor of x, excluding x itself
int next(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return x / i;
        }
    }
    return 1; // If x is a prime number, return 1
}

// Function to calculate the minimum number of operations to make Ai equal to Bi
int minOperations(int a, int b) {
    int operations = 0;
    while (a != b) {
        if (a < b) swap(a, b); // Ensure a is always the larger number
        a = next(a);
        ++operations;
    }
    return operations;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the arrays
        vector<int> A(n), B(n);

        // Input for array A
        for (int i = 0; i < n; ++i) cin >> A[i];

        // Input for array B
        for (int i = 0; i < n; ++i) cin >> B[i];

        int totalOperations = 0;
        for (int i = 0; i < n; ++i) {
            totalOperations += minOperations(A[i], B[i]);
        }

        cout << totalOperations << "\n";
    }

    return 0;
}
