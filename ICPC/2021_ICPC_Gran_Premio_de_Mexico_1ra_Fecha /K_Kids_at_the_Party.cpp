#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
typedef long long ll;

// 2 3 4 5 6
bool d2 (string s) {
    int d = s.back() - '0';
    return !(d & 1);
}

bool d3 (string s) {
    ll sum = 0;
    for (auto x: s) {
        sum += x - '0';
    }
    return (sum % 3 == 0);
}

bool d4 (string s) {
    ll num = 0;
    if (sz(s) == 1) {
        num = s[0] - '0';
    }
    else {
        string aux = "";
        aux += s[sz(s) - 2];
        aux += s.back();

        num = stoll(aux);
    }

    return num % 4 == 0;
}

bool d5 (string s) {
    int ult = s.back() - '0';
    return (ult == 0 || ult == 5);
}

bool d6 (string s) {
    return (d2(s) && d3(s));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        string n;
        cin >> n;

        vector<int> res;
        if (d2(n))  res.push_back(2);
        if (d3(n))  res.push_back(3);
        if (d4(n))  res.push_back(4);
        if (d5(n))  res.push_back(5);
        if (d6(n))  res.push_back(6);

        if (!sz(res)) {
            res = {-1};
        }

        for (int i = 0; i < sz(res); i++) {
            cout << res[i] << " \n"[i == sz(res) - 1];
        }
    }

    return 0;
}