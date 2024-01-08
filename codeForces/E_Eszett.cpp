#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol(){
    string s;
    cin >> s;
    int n = s.size();

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << "\n";

    for(int i = 0; i < n - 1; i++) {
        if(s[i] == 's' && s[i] == s[i + 1]) {
            cout << s.substr(0, i) << "B" << s.substr(i + 2) << "\n";
        }
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