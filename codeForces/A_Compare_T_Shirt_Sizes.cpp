#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";
 
typedef long long ll;
typedef long double ld;
 
const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    string a, b;
    cin >> a >> b;

    if(a == b) {
        cout << "=\n";
        return;
    }

    if (a.back() != b.back()) {
        if (a.back() < b.back()) {
            cout << ">\n";
        } 
        else {
            cout << "<\n";
        }
    } 
    else {
        if (a.back() == 'S') {
            if (a.size() < b.size()) {
                cout << ">\n";
            }
            else {
                cout << "<\n";
            }
        } else {
            if (a.size() > b.size()) {
                cout << ">\n";
            }
            else {
                cout << "<\n";
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}