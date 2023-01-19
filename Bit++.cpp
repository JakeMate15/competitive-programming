#include <bits/stdc++.h>

using namespace std;

int res = 0;

void sol(){
    string s;cin >> s;

    if(s.find("++")!=std::string::npos){
        res++;
    }
    else{
        res--;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;

    while (t--){
        sol();
    }
    

    cout << res << endl;

    return 0;
}