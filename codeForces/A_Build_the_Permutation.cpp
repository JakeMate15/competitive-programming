#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol(){
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b > n - 2 || abs(a - b) > 1) {
        cout << "-1\n";
        return;
    }

    vector<int> p(n);
    if (a > b) {
        int lo = 1, hi = n;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                p[i] = hi--;
            }
            else {
                p[i] = lo++;
            }
        }
        sort(p.begin() + 1 + a + b, p.end());
        reverse(p.begin() + 1 + a + b, p.end());
    } 
    else if (a < b) {
        int lo = 1, hi = n;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                p[i] = lo++;
            }
            else {
                p[i] = hi--;
            }
        }
            
        sort(p.begin() + 1 + a + b, p.end());
    } 
    else if (a == b) {
        int lo = 1, hi = n;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                p[i] = hi--;
            }
            else {
                p[i] = lo++;
            }
        }
            
        sort(p.begin() + 1 + a + b, p.end());
    }
    
    for (int x : p) {
        cout << x << ' ';
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}