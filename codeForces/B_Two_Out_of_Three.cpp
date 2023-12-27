#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n;
    cin >> n;

    vector<int> b(101), a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }

    vector<int> aux;
    for(int i = 1; i <= 100; i++) {
        if(b[i] >= 2) {
            aux.push_back(i);
        }
    }

    
    if(sz(aux) < 2) {
        cout << -1 << "\n";
    } 
    else {
        vector<int> res(n, 1);
        res[find(all(a), aux[0]) - a.begin()] = 2;
        res[find(all(a), aux[1]) - a.begin()] = 3;
        for(int i = 0; i < n; i++) {
            cout << res[i] << " \n"[i == n - 1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}