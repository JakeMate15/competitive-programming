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
    string s;
    cin >> s;

    map<int, int> rep;
    for(char c: s) {
        rep[c]++;
    }

    int h = min(rep['L'], rep['R']), v = min(rep['U'], rep['D']);
    h = (v == 0 ? min(h, 1): h);
    v = (h == 0 ? min(v ,1): v);

    cout << 2 * (h + v) << "\n";
    for(int i = 0; i < h; i++) {
        cout << "R";
    }
    for(int i = 0; i < v; i++) {
        cout << "U";
    }
    for(int i = 0; i < h; i++) {
        cout << "L";
    }
    for(int i = 0; i < v; i++) {
        cout << "D";
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