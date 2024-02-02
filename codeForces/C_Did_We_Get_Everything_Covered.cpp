#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void sol(){
    int n, k, m;
    string s;
    cin >> n >> k >> m >> s;

    vector<int> cnt(26);
    for (char c: s) {
        cnt[c - 'a']++;
    }
 
    for (int i = 0; i < k; i++) {
        if (cnt[i] < n) {
            cout << "NO\n";
            char c = 'a';
            for (int j = 0; j < n; j++) {
                cout << (char)(c + i);
            }
            cout << "\n";
            return;
        }
    }

    vector<pair<char, int>> nc(m);
    for (int i = 0; i < n; i++) {
        nc[i] = {s[i], i};
    }

    sort(nc.begin(), nc.end());

    string res = "";
    bool f = false; 
    int ant = 0;
    char c = 'a';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            auto it = lower_bound(nc.begin(), nc.end(), {c + });
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}