#include <bits/stdc++.h>

using namespace std;

void sol(){
    int w,d,h;
    int a,b,f,g;

    cin >> w >> d >> h;
    cin >> a >> b >> f >> g;

    if(a==f || g==b){
        cout << h + 
    }
    else{
        cout << abs(a-f) + h + b + g << "\n";
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while (t--){
        sol();
    }
    



    return 0;
}