#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef int ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

/*
    x = a / b + c
    We can only use +, -, sqrt()

    c = 0
    x = a / b
    x * b = a

    n2 * b <= a
    a = 10, b = 3
    x * 3 <= 10

    x * 3 = x + x + x

    n5 * b > a
    [n1, n2, n3, n4, n5, n6]

    x * b <= a

    a > 0, b > 0    ->  [0, sqrt(a)] sqrt(a) = 2^16 = 65536
    a < 0, b < 0    ->  [0, sqrt(a)]
    
    a > 0, b < 0   ->  [-sqrt(a), -1] 
    a < 0, b > 0   ->  [-sqrt(a), -1]

    a >= 0 or b < 0 ->  [0, sqrt(a)]
                    ->  [-sqrt(a), -1]


    

    greatest x such that 
    x * b <= a

    a > 0:
        b > 0: [-inf, a]
        b < 0; []

    a < 0:
        b > 0: 

        b < 0;


    

*/


int divide(int dividend, int divisor) {
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
    dividend = abs(dividend);
    divisor = abs(divisor);
 
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
 
    return quotient * sign;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << divide(a, b);
    }

    return 0;
}

/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the case where dividend is equal to divisor
        if (dividend == divisor) return 1;

        unsigned int ans = 0;
        int sign = 1;

        // Determine the sign of the result
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;

        // Convert both dividend and divisor to positive integers
        unsigned int n = abs(dividend), d = abs(divisor);

        // Perform the division
        while (n >= d) {
            int count = 0;
            while (n > (d << (count + 1)))
                count++;
            n -= d << count;
            ans += 1 << count;
        }

        // Handle overflow case
        if (ans == (1 << 31) && sign == 1) return INT_MAX;

        return sign * ans;
    }
};

*/