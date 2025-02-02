#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<unsigned long long>> A(n, vector<unsigned long long>(m));
        vector<vector<unsigned long long>> B(n, vector<unsigned long long>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> A[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> B[i][j];
            }
        }

        bool possible = true;
        for(int bit = 0; bit < 32; bit++){
            vector<bool> rowMustZero(n, false), colMustOne(m, false);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    unsigned long long aBit = (A[i][j] >> bit) & 1ULL;
                    unsigned long long bBit = (B[i][j] >> bit) & 1ULL;
                    if(aBit == 1 && bBit == 0) rowMustZero[i] = true;
                    if(aBit == 0 && bBit == 1) colMustOne[j] = true;
                }
            }
            for(int i = 0; i < n && possible; i++){
                for(int j = 0; j < m && possible; j++){
                    unsigned long long bBit = (B[i][j] >> bit) & 1ULL;
                    if(rowMustZero[i] && colMustOne[j]){
                        possible = false;
                        break;
                    }
                    if(rowMustZero[i] && bBit == 1){
                        possible = false;
                        break;
                    }
                    if(colMustOne[j] && bBit == 0){
                        possible = false;
                        break;
                    }
                }
            }
            if(!possible) break;
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}
