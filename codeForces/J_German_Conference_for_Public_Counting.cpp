#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol(){
    ll n;
    cin >> n;

    if(n < 10) {
        cout << n + 1 << "\n";
        return;
    }

    ll res = 1;

    for(int i = 1; i <= 9; i++) {
        ll aux = i;
        while(aux * 10 + i <= n) {
            aux = aux * 10 + i;
        }
        res += log10(aux) + 1;
    }

    ll aux = 100;
    while(aux <= n) {
        res++;
        aux *= 10;
    }
 
    cout << res << "\n";
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