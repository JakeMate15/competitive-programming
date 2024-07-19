#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int) a.size()

typedef long long ll;
typedef pair<int, int> ii;

int main () {
    char d;
    int a[15];
    int n, x, mn;
    mn = 1e6;
    cin >> n;

    for (int i = 0; i < 9; i++) {
        cin >> x;
        a[i+1] = x;
        if(x <= mn){
            mn = x;
            d = i+1 + '0';
        }
    }
    if(n < mn){
        cout << "-1\n";
        return 0;
    }

    ll k = (n / mn);
    ll c = 1LL * k * mn;

    string s;
    for (int i = 0; i < k; i++) {
        s.push_back(d);
    }

    for (int i = 0; i < k; i++) {
        c -= mn;
        for(int j = 9; j >= d - '0'; j--){
            if(j + '0' == d){
                c += mn;
                break;
            }
            if(c + a[j] <= n) {
                s[i] = j+'0';
                c += a[j];
                break;
            }
        }
    }

    cout << s << "\n";

    return 0;
}