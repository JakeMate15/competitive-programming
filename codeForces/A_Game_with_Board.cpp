#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

/*

11 -> 2
bob

111 -> 3
bob

1111 -> 112/13/4
bob

alice    bob     alice  -> bob
11111 -> 1112 -> 122 -> 13


*/

void sol(){
    int n;
    cin >> n;
    
    if(n <= 4) {
        cout << "Bob\n";
    }
    else {
        cout << "Alice\n";
    }
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