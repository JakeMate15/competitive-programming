#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b, int M) {
    vector<vector<int>> res(M, vector<int>(M, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < M; ++k) {
                res[i][j] = (res[i][j] + (long long)a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }
    return res;
}

vector<vector<int>> binPow(vector<vector<int>> base, int N, int M) {
    vector<vector<int>> res(M, vector<int>(M, 0));
    for (int i = 0; i < M; ++i) {
        res[i][i] = 1;
    }
    while (N > 0) {
        if (N & 1) res = mul(res, base, M);
        base = mul(base, base, M);
        N >>= 1;
    }
    return res;
}

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<int>> mat(M, vector<int>(M, 0));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (gcd(i, j) == 1) {
                mat[i-1][j-1] = 1;
            }
        }
    }
    
    vector<vector<int>> res = binPow(mat, N-1, M);
    ll ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            ans = (ans + res[i][j]) % mod;
        }
    }
    
    cout << ans << "\n";

    return 0;
}