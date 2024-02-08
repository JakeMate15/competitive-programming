#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol(){
    string s;
    cin >> s;

    if (s == "abc" || s == "acb" || s == "bac" || s == "cba") {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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