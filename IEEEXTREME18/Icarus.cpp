#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MX = 4001;
const int MOD = 1E9 + 7;

void sol () {
    string s;
    cin >> s;

    int tam = sz(s), A = 1, B = 2, N = 1; ;
    vector<int> l(MX, 0), r(MX, 0), p(MX, 0);
    
    vector<bool> vis(MX, false),visL(MX, false), visR(MX, false);
    int curr = A;
    vis[curr] = true;
    int lim = 2 * tam;
    for(int i = 0; i < lim; i++){
        char c = s[i % tam];
        if(c == 'L'){
            visL[curr] = true;
            if(l[curr] == 0){
                int nxt = N + 1;
                if(nxt == B){
                    nxt++;
                }
                if(nxt > 2 * tam){
                    break;
                }
                l[curr] = nxt;
                p[nxt] = curr;
                curr = nxt;
                if(curr == B){
                    continue;
                }
                if(N < nxt){
                    N = nxt;
                }
            }
            else{
                curr = l[curr];
            }
        }
        else if(c == 'R'){
            visR[curr] = true;
            if(r[curr] == 0){
                int nxt = N + 1;
                if(nxt == B){
                    nxt++;
                }
                if(nxt > 2 * tam){
                    break;
                }
                r[curr] = nxt;
                p[nxt] = curr;
                curr = nxt;
                if(curr == B){
                    continue;
                }
                if(N < nxt){
                    N = nxt;
                }
            }
            else{
                curr = r[curr];
            }
        }
        else if(c == 'U'){
            if(p[curr] != 0){
                curr = p[curr];
            }
        }
        vis[curr] = true;
    }

    bool ok = false;
    for(int u = 1; u <= N; u++){
        if(vis[u]){
            if(!visL[u] && l[u] == 0){
                l[u] = B;
                p[B] = u;
                ok = true;
                break;
            }
            if(!visR[u] && r[u] == 0){
                r[u] = B;
                p[B] = u;
                ok = true;
                break;
            }
        }
    }
    if(!ok) {
        cout << "-1";
    }
    N = max(N, B);
    cout << N << " " << A << " " << B << "\n";
    for(int u = 1; u <= N; u++){
        if(u >= MX){
            cout << "0 0\n";
            continue;
        }
        cout << l[u] << " " << r[u] << "\n";
    }  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    // cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}