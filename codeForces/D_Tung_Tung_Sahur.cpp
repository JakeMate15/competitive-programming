#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()

void sol () {
    string a, b;
    cin >> a >> b;

    vector<string> A, B;
    int i = 0, j = 0;
    while (i < sz(a) || j < sz(b)) {
        char curr = a[i];
        string aux = "";
        while (i < sz(a) && a[i] == curr) {
            aux += curr;
            i++;
        }
        if (aux != "") {
            A.push_back(aux);
        }

        curr = b[j];
        aux = "";
        while (j < sz(b) && b[j] == curr) {
            aux += curr;
            j++;
        }
        if (aux != "") {
            B.push_back(aux);
        }
    }

    if (sz(A) != sz(B)) {
        cout << "NO\n";
        return;
    }

    for (i = 0; i < min(sz(A), sz(B)); i++) {
        if (A[i][0] != B[i][0] || sz(A[i]) * 2 < sz(B[i]) || sz(A[i]) > sz(B[i])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}