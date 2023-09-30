#include<bits/stdc++.h>
using namespace std;

void sol(int t){
    int s, d, k;
    cin >> s >> d >> k;

    cout << "Case #" << t << ": ";
    cout << ((2 * (s + d) >= k + 1 && s + 2 * d >= k)? "YES": "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    for(int i = 1; i <= t; i++){
        sol(i);
    }

    return 0;
}