#include<bits/stdc++.h> 
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> t(n), s(m);
    for (auto &p : t) {
        cin >> p.first >> p.second;
        p.second++;
    }

    for (auto &p : s) {
        cin >> p.first >> p.second;
        p.second++;
    }

    map<int, vector<pair<int,int>>> e;
    for (int i = 0; i < n; i++){
        int L = t[i].first, R = t[i].second;
        e[L].push_back({0, i});
        e[R].push_back({1, i});
    }

    for (int i = 0; i < m; i++){
        int L = s[i].first, R = s[i].second;
        e[L].push_back({2, i});
        e[R].push_back({3, i});
    }

    vector<int> r(m, 0);
    vector<pair<int,int>> v;
    int a = 0, b = 0;
    for (auto &p : e) {
        int x = p.first;
        auto &c = p.second;
        for (auto &q : c) {
            int k = q.first, i = q.second;
            if (k != 3)
                continue;
            int j = (int)v.size() - 1;
            while (j && v[j-1].first >= s[i].first)
                j--;
            r[i] = v[j].second;
        }
        for (auto &q : c) {
            int k = q.first;
            a += (k == 0);
            a -= (k == 1);
            b += (k == 2);
            b -= (k == 3);
        }
        int d = b ? (a + b - 1) / b : 0;
        while (!v.empty() && v.back().second <= d)
            v.pop_back();
        v.push_back({x, d});
    }
    for (int i = 0; i < m; i++)
        cout << r[i] << (i < m - 1 ? " " : "\n");
    return 0;
}
