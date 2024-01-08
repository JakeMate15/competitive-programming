#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol(){
    int n;
    cin >> n;

    if(n > 9) {
        cout << "1 2 3\n";
    }
    else if(n == 2) {
        cout << "100 10 1\n";
    }
    else if(n == 1) {
        cout << "10 40 100\n";
    }
    else {
        cout << "1 60 100\n";
    }
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