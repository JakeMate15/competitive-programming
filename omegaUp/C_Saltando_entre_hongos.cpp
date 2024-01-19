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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<int> aux(n);
    aux[0] = 0;
    for(int i = 1; i < n; i++) {
        aux[i] = max(0, a[i] - a[i - 1]);
        // cerr << aux[i] << " ";
    }

    auto mx = *max_element(all(aux));
    if(mx > m) {
        cout << "IMPOSIBLE " << mx;
    }
    else {
        cout << "POSIBLE";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}