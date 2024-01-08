#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

i j -> j , n - i + 1

i           j
j           n - 1 - i
n - 1 - i   n - 1 - j
n - 1 - j   i

*/

// vector<pair<int, int>> a;
// for(auto x: rep) {
//     a.push_back(x);
// }

// sort(a.begin(), a.end(), cmp);

// for(auto x: a) {
//     cerr << x.first << " " << x.second << "\n";
// }

// vector<vector<int>> res(n, vector<int>(n));

// for(int i = 0; i < n / 2; i++) {
//     for(int j = 0; j < n / 2; j++) {
//         if(a.size() == 0 || (a.back().second) < 4) {
//             cout << "NO\n";
//             return;
//         }
//         // cerr << rep.begin() -> second << "\n";
//         res[i][j] = res[j][n - 1 - i] = res[n - 1 - i][n - 1 - j] = res[n - 1 - j][i] = a.back().first;
//         a.back().second -= 4;
//         if(a.back().second <= 0) {
//             a.pop_back();
//         }
//     }
// }

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void sol(){
    int n;
    cin >> n;

    map<int, int> rep;

    for (int i = 0; i < n * n; i++) {
        int v; 
        cin >> v;
        rep[v]++;
    }


    vector<vector<int>> res(n, vector<int>(n));

    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            for(auto &[v, r]: rep) {
                if(r >= 4) {
                    r -= 4;
                    res[i][j] = res[i][n - 1 - j] = res[n - 1 - i][n - 1 - j] = res[n - 1 - i][j] = v;
                    break;
                }
            }
            if(!res[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    if(n & 1) {
        int m = n / 2;
        for(int i = 0; i < m; i++) {
            // cerr << "m\n";
            for(auto &[v, r]: rep) {
                // cerr << v << " " << r << "\n";
                if(r >= 2) {
                    r -= 2;
                    res[i][m] = res[n - 1 - i][m] = v;
                    break;
                }
            }

            for(auto &[v, r]: rep) {
                // cerr << v << " " << r << "\n";
                if(r >= 2) {
                    r -= 2;
                    res[m][i] = res[m][n - 1 - i] = v;
                    break;
                }
            }

            if(!res[i][m] || !res[m][i]) {
                cout << "NO\n";
                return;
            }
        }
        for(auto &[v, r]: rep) {     
            if(r) {
                res[m][m] = v;
                break;
            }
        }
    }

    cout << "YES\n";
    for(auto x: res) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << "\n";
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