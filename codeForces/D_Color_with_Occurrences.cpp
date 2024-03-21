#include<bits/stdc++.h>

using namespace std;
#define sz(a)   (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

struct kmp{
    vector<int> aux;
    string pattern;

    kmp(string pattern){
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

    vector<int> search(string & text){
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

void sol() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> patrones(n);
    vector<tuple<int, int, int>> segmentos;
    int primero = -1, tam = 0;

    for (int i = 0; i < n; i++) {
        cin >> patrones[i];
        
        vector<int> aux;
        kmp k(patrones[i]);
        auto f = k.search(s);
        for (auto x: f) {
            segmentos.emplace_back(x, x + sz(patrones[i]) - 1, i);
            if (x == 0 && sz(patrones[i]) > tam) {
                primero = i;
            }
        }
    }

    if (primero == -1) {
        cout << "-1\n";
        return;
    }

    vector<ii> res;
    for (int i = 0; i < sz(s); i++) {
        int mejor = -1, tam = i - 1, aa = -1;
        for (auto [a, b, ii]: segmentos) {
            if (a <= i && i <= b && b > tam) {
                mejor = ii;
                tam = b;
                aa = a;
            }
        }

        if (mejor == -1) {
            cout << "-1\n";
            return;
        }

        res.emplace_back(mejor, aa);
        i = tam;
    }

    cout << sz(res) << "\n";
    for (auto [a, b] : res) {
        cout << a + 1 << " " << b + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}