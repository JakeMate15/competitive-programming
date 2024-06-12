#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()

typedef long long ll;

int main () {
    int n;
    cin >> n;
 
    ll res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
 
        for (int j = 0; j < sz(s); j++) {
            int curr = 0;
            while (s[j] == 'N') {
                j++;
                curr++;
            }
            res += curr / 2;
        }
    }
 
    cout << res << "\n";

}