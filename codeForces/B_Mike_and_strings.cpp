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

    map<string, pair<int, set<int>>> a;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int tam = sz(s);

        set<string> rep;
        for(int j = 0; j < tam; j++) {
            string aux = s;
            rotate(aux.begin(), aux.begin() + j, aux.end());
            // cerr << aux << " " << j << '\n';

            if(rep.count(aux)) {
                continue;
            }
            rep.insert(aux);

            a[aux].first += j;
            a[aux].second.insert(i);
        }
        // cerr << "\n\n";
    }


    // cerr << "====================";
    int res = INT_MAX;
    for(auto x: a) {
        // cerr << x.first << " " << x.second.first << "\n";
        // for(auto y: x.second.second) {
        //     cerr << y << "\n";
        // }
        // cerr << "\n";


        if(sz(x.second.second) == n) {
            res = min(res, x.second.first);
        }
    }

    cout << (res == INT_MAX ? -1 : res) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}


/*

abcabc 0
bcabca 1
cabcab 2
abcabc 3
bcabca 4
cabcab 5


cabcab 0
abcabc 1
bcabca 2
cabcab 3
abcabc 4
bcabca 5

*/