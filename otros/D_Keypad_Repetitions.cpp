#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void sol(){
    int n, q;
    cin >> n >> q;

    map<char, int> mp = {
        {'a', 2},
        {'b', 2},
        {'c', 2},
        {'d', 3},
        {'e', 3},
        {'f', 3},
        {'g', 4},
        {'h', 4},
        {'i', 4},
        {'j', 5},
        {'k', 5},
        {'l', 5},
        {'m', 6},
        {'n', 6},
        {'o', 6},
        {'p', 7},
        {'q', 7},
        {'r', 7},
        {'s', 7},
        {'t', 8},
        {'u', 8},
        {'v', 8},
        {'w', 9},
        {'x', 9},
        {'y', 9},
        {'z', 9}
    };

    map<string, int> a;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string nvo = "";
        for(char x: s) {
            nvo += mp[x] + '0';
        }
        // cerr << nvo << "\n";
        a[nvo]++;
    }

    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;

        cout << a[s] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}