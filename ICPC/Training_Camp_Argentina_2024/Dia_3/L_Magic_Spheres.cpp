#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    int aux = 0;
    if (a > x) {
        aux += (a - x)/2*2;
        a = x;
    }
    if (b > y) {
        aux += (b - y)/2*2;
        b = y;
    }
    if (c > z) {
        aux += (c - z)/2*2;
        c = z;
    }
    if (a < x) {
        aux -= (x - a) * 2;
    }
    if (b < y) {
        aux -= (y - b) * 2;
    }
    if (c < z) {
        aux -= (z - c) * 2;
    }

    cout << (aux >= 0 ? "Yes" : "No") << "\n";

    return 0;
}
