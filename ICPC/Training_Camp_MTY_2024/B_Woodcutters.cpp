#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1e9 + 7;
const int MX = 1e9 + 5;

int main () {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int res = (n >= 2 ? 2 : 1);
    int anterior = a[0];
    for (int i = 1; i < n - 1; i++) {
        if (a[i] - b[i] > anterior) {
            res++;
            anterior = a[i];
        }
        else if (a[i] + b[i] < a[i + 1]) {
            res++;
            anterior = a[i] + b[i];
        }
        else {
            anterior = a[i];
        }
    }

    cout << res << "\n";


    return 0;
}