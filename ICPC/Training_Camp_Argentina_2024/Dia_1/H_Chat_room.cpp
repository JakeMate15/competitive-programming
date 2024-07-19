#include<bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;

    string a = "hello";
    int idx = 0;

    for (auto x: s) {
        if (idx < 5 && a[idx] == x) {
            idx++;
        } 
    }

    if (idx >= 5) {
        cout << "YES\n";
    }
    else
        cout << "NO\n";

    return 0;
}