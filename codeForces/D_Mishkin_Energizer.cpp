#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void val () {
    int n; 
    string s;
    cin >> n >> s;

    bool eq = true;
    int cntL = 0, cntI = 0, cntT = 0;
    for(char c : s){
        eq &= c == s[0];
        if(c=='L') 
            cntL++;
        else if(c=='I') 
            cntI++;
        else 
            cntT++;
    }

    if(n == 1 || eq){
        cout << -1 << "\n";
        return;
    }

    bool val = false;
    int lb = max({max(cntL, cntI), cntT, (n + 2) / 3});
    for (int k = lb; k <= n; k++){
        int m = 3 * k - n;
        vector<int> nec(3, 0);
        nec[0] = k - cntL;
        nec[1] = k - cntI;
        nec[2] = k - cntT;
        string curr = s;
        vector<int> ops;
        bool ok = true;
        for (int op = 0; op < m; op++){
            bool f = false;
            for (int i = 0; i < sz(curr) - 1; i++){
                if(curr[i] == curr[i + 1])
                    continue;
                char a = curr[i], b = curr[i + 1], aux;
                if((a == 'L' && b == 'I') || (a == 'I' && b == 'L')) 
                    aux = 'T';
                else if((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) 
                    aux = 'I';
                else 
                    aux = 'L';
                int idx = (aux == 'L' ? 0 : (aux == 'I' ? 1 : 2));
                if(nec[idx] > 0){
                    ops.push_back(i + 1);
                    curr.insert(curr.begin() + i + 1, aux);
                    nec[idx]--;
                    f = true;
                    break;
                }
            }
            if(!f){ 
                ok = false; 
                break; 
            }
        }
        if(ok && nec[0] == 0 && nec[1] == 0 && nec[2] == 0){
            cout << sz(ops) << "\n";
            for(auto x : ops) {
                cout << x << "\n";
            }
            val = true;
            return;
        }
    }
    
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        val();
    }

    return 0;
}