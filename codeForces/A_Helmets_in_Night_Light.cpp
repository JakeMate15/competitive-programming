#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    sort(all(a));
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({p, n});
    ll res = 0;

    for(int i = 0; i < n; i++) {
        auto m = pq.top();  pq.pop();
        res += m.first;
        m.second--;

        if(m.second > 0) {
            pq.push(m);
        }

        pq.push(a[i]);
    }

    cout << res << "\n";
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