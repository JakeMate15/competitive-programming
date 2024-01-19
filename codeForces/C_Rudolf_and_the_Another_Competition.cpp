#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct p{
    ll cnt = 0, sum = LONG_LONG_MAX, r = 0;
};

bool cmp(p a, p b) {
    if(a.cnt == b.cnt) {
        if(a.sum == b.sum) 
            return a.r == 1;

        return a.sum < b.sum;
    }

    return a.cnt > b.cnt;
}

void sol(){
    // cerr << "============\n";
    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<int>> a(n, vector<int>(m));
    vector<p> aux(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }

        sort(all(a[i]));

        for(int k = 1; k < m; k++) {
            a[i][k] += a[i][k - 1];
        }

        ll cnt = 0, sum = 0;
        for(auto x: a[i]) {
            if(x > h) {
                break;
            }
            cnt++;
            sum += x;
        }
        
        aux[i].cnt = cnt, aux[i].sum = sum, aux[i].r = (i == 0 ? 1 : 0); 
        // cerr << cnt << " " << sum << "\n";
    }

    sort(all(aux), cmp);

    for(int i = 0; i < n; i++) {
        if(aux[i].r) {
            cout << i + 1 << '\n';
            return;
        }
    }
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