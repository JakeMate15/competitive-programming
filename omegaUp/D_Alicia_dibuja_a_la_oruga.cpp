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
    int n;
    cin >> n;

    vector<vector<char>> a(5, vector<char>(n + 5, ' '));

    int dir = 1;
    for(int j = 0, i = 2; j < n; j++) {
        a[i][j] = 'O';
        if(dir) {
            i--;
            if(i == 0) {
                dir = 0;
                a[i][++j] = 'O';
            }
        }
        else {
            i++;
            if(i == 4) {
                dir = 1;
                a[i][++j] = 'O';
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        int lastO = n - 1;
        while(lastO >= 0 && a[i][lastO] == ' ') {
            lastO--;
        }
        for(int j = 0; j <= lastO; j++) {
            cout << a[i][j];
        }
        nl;
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