#include<bits/stdc++.h>
using namespace std;

#define all(v)    v.begin(),v.end()
#define sz(a)    (int)a.size()
#define nl        cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct kmp{
    vector<int> aux,pattern;

    kmp(vector<int> pattern){
        this->pattern = pattern;
        aux.resize(pattern.size());
        int i = 1, j = 0;
        while(i < pattern.size()){
            if(pattern[i] == pattern[j])
                aux[i++] = ++j;
            else{
                if(j == 0) aux[i++] = 0;
                else j = aux[j - 1];
            }
        }
    }

    vector<int> search(vector<int> & text){
        vector<int> ans;
        int i = 0, j = 0;
        while(i < text.size() && j < pattern.size()){
            if(text[i] == pattern[j]){
                ++i, ++j;
                if(j == pattern.size()){
                    ans.push_back(i - j);
                    j = aux[j - 1];
                }
            }else{
                if(j == 0) ++i;
                else j = aux[j - 1];
            }
        }
        return ans;
    }
};

void sol(){
    int n, m;
    cin >> n >> m;

    if(n == 1) {
        cout << m << "\n";
        return;
    }

    vector<int> b(n), a(m);
    for(auto &x: b) {
        cin >> x;
    }
    for(auto &x: a) {
        cin >> x;
    }

    vector<int> patron, cad;
    for(int i = 1; i < sz(b); i++) {
        patron.push_back(b[i] - b[i - 1]);
    }
    for(int i = 1; i < sz(a); i++) {
        cad.push_back(a[i] - a[i - 1]);
    }

    kmp k(patron);
    auto res = k.search(cad);
    cout << sz(res) << "\n";

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