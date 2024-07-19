#include<bits/stdc++.h>
using namespace std;

int main () {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    while(a>0 and c>0 and d>0)
    {
        a--;
        c--;
        d--;
        ans += 256;
    }
    while(a>0 and b>0){
        a--;
        b--;
        ans+=32;
    }
    cout << ans;

    return 0;
}