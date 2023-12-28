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
    int n = sz(s);

    if(count(all(s), '?') == n) {
        replace(all(s), '?', '1');
        cout << s << "\n";
        return;
    }

    vector<char> aux = {'0', '1'};
    auto prim = find_first_of(all(s), all(aux));
    auto ult = find_first_of(s.rbegin(), s.rend(), all(aux));

    replace(s.begin(), prim, '?', *prim);
    replace(s.rbegin(), ult, '?', *ult);

    char ant = s[0];    
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            s[i] = ant;
        }
        else {
            ant = s[i];
        }
    }

    cout << s << "\n";
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