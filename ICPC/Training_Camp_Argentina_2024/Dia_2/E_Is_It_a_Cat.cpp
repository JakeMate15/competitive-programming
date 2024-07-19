#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

void sol () {
    int n;
    string s;
    cin >> n >> s;

    string aux = "";
    for(char &x: s){
        aux += tolower(x);
    }

    aux.erase(unique(all(aux)), aux.end());

    cout << (aux == "meow" ? "YES" : "NO") << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}