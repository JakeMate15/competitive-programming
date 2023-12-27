#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

const int dr[] = {1,-1,0,0,1,-1,-1,1};
const int dc[] = {0,0,1,-1,1,1,-1,-1};

bool ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void sol(){
    vector<string> a(3);
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    set<string> res;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            string s1 = "";
            s1 += a[i][j];
            pair<int, int> p1 = {i, j};

            for(int k = 0; k < 8; k++) {
                pair<int, int> p2 = {p1.first + dr[k], p1.second + dc[k]};

                if(!ok(p2.first, p2.second, 3, 3)) {
                    continue;
                }
                string s2 = s1 + a[p2.first][p2.second];

                for(int l = 0; l < 8; l++) {
                    pair<int, int> p3 = {p2.first + dr[l], p2.second + dc[l]};
                    
                    if(!ok(p3.first, p3.second, 3, 3)) {
                        continue;
                    }

                    string s3 = s2 + a[p3.first][p3.second];
                    set<pair<int, int>> aux = {p1, p2, p3};
                    
                    if(sz(aux) == 3) {
                        res.insert(s3);
                    }
                }
            }
        }
    }

    cout << *res.begin() << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}