#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void sol () {
    int n;
    cin >> n;
    
    vector<int> x = {1, 2, 3};
    while (true) {
        cout << "? " << i[0] << " " << i[1] << " " << i[2] << endl;
        int p;
        cin >> p;
        
        if (p == 0) {
            break;
        }
        
        int x = rng() % 3;
        i[x] = p;
    }
    
    cout << "! " << i[0] << " " << i[1] << " " << i[2] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}