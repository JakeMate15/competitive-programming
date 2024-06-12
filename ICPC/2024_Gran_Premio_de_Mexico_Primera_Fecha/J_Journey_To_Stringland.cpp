#include<bits/stdc++.h>
using namespace std;

const int inf = INT_MAX / 2;

int n, k;
string s;
int dp[505][505][255], vis[505][505][255];

// dp(l, r, k) = cantidad min de caracteres para tener un pal de tam k
int go (int l, int r, int tam) {
    if (tam == k)
        return 0;
    if (l == r)
        return (tam == k - 1 ? 0: inf);
    if (l > r)
        return inf;
        
    int &v = vis[l][r][tam];
    int &mem = dp[l][r][tam];
    if (v)
        return mem;

    v = 1;
    mem = inf;

    return mem = min({
        go(l + 1, r - 1, tam + 2) + (s[l] == s[r] ? 0 : 1),
        go(l + 1, r, tam),
        go(l, r - 1, tam)
    });
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> s;
    cout << go(0, n - 1, 0);

    return 0;
}