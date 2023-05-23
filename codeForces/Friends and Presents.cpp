#include <iostream>
using namespace std;
long long a, b, x, y;
 
long long ok(long long n) {
    long long oa = n / x;
    long long ob = n / y;
    long long oab = n / x / y;
 
    long long com = n - oa - ob + oab;
    long long ca = n - oa;
    long long cb = n - ob;
    return ca >= a && cb >= b && ca + cb - com >= a + b;
}
 
int main() {
    cin >> a >> b >> x >> y;
    long long l = max(a, b), r = 1e13;
    while(l < r) {
        long long m = (l + r) >> 1;
        if(!ok(m)) l = m + 1;
        else r = m;
    }
    cout << r << endl;
    return 0;
}