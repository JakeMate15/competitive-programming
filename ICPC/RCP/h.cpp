#include <iostream>
using namespace std;

typedef long long ll;

ll DIV(ll a, ll b) {
    if(a >= 0) return a / b;
    else return -((-a + b - 1) / b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, c;
    cin >> x >> c;
    if(x <= c) { 
        cout << 0 << "\n"; 
        return 0; 
    }
    
    x -= c;
    for(ll k = 1; k < c; k++){
        ll d = DIV(c - x, k + 1);
        x -= d;
        if(x <= 0){ 
            cout << k << "\n"; 
            return 0; 
        }
    }

    cout << "impossible" << "\n";
    
    return 0;
}
