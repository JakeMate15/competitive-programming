#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    int n, m;
    cin >> n >> m;

    debln((m == 1 ? 0 : min(n + 1, m)));
    for(int i = 0; i < n; i++) {
        vector<int> aux(m);
        iota(all(aux), 0);

        int lim = max(1, m - 1 - i);
        reverse(aux.begin(), aux.begin() + lim);
        reverse(aux.begin() + lim, aux.end());

        for(auto x: aux) {
            deb(x);
        }

        nl();
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}