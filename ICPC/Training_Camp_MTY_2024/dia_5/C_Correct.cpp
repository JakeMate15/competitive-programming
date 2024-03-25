#include<bits/stdc++.h>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;

    int t = 9 * 60;
    cout << max(0, a * 60 + b - t);
    return 0;
}