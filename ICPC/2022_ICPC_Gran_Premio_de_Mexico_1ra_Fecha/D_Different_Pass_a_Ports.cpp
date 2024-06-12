#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

template <typename T>
struct matrix{
    vector<vector<T>> A;
    int m, n;
 
    matrix(int m, int n): m(m), n(n){
        A.resize(m, vector<T>(n, 0));
    }
 
    vector<T> & operator[] (int i){
        return A[i];
    }
 
    const vector<T> & operator[] (int i) const{
        return A[i];
    }
 
    static matrix identity(int n){
        matrix<T> id(n, n);
        for(int i = 0; i < n; i++)
            id[i][i] = 1;
        return id;
    }
 
    matrix operator+(const matrix & B) const{
        assert(m == B.m && n == B.n); //same dimensions
        matrix<T> C(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                (C[i][j] = A[i][j] + B[i][j]) %= mod;
        return C;
    }
 
    matrix operator+=(const matrix & M){
        *this = *this + M;
        return *this;
    }
 
    matrix operator-() const{
        matrix<T> C(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                C[i][j] = -A[i][j];
        return C;
    }
 
    matrix operator-(const matrix & B) const{
        return *this + (-B);
    }
 
    matrix operator-=(const matrix & M){
        *this = *this + (-M);
        return *this;
    }
 
    matrix operator*(const matrix & B) const{
        assert(n == B.m); 
        matrix<T> C(m, B.n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < B.n; j++)
                for(int k = 0; k < n; k++)
                    (C[i][j] += A[i][k] * B[k][j]) %= mod;
        return C;
    }
 
    matrix operator*(const T & c) const{
        matrix<T> C(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                C[i][j] = A[i][j] * c;
        return C;
    }
 
    matrix operator*=(const matrix & M){
        *this = *this * M;
        return *this;
    }
 
    matrix operator*=(const T & c){
        *this = *this * c;
        return *this;
    }
 
    matrix operator^(ll b) const{
        matrix<T> ans = matrix<T>::identity(n);
        matrix<T> A = *this;
        while(b){
            if(b & 1) ans *= A;
            b >>= 1;
            if(b) A *= A;
        }
        return ans;
    }
 
    matrix operator^=(ll n){
        *this = *this ^ n;
        return *this;
    }
 
    bool operator==(const matrix & B) const{
        if(m != B.m || n != B.n) return false;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(A[i][j] != B[i][j]) return false;
        return true;
    }
 
    bool operator!=(const matrix & B) const{
        return !(*this == B);
    }
 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    matrix<ll> mat(n, n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        mat.A[u][v] = 1;
        mat.A[v][u] = 1;
    }

    mat^=k;

    int res = 0;
    for (int i = 0; i < n; i++) {
        (res += mat.A[i][0]) %= mod;
    }

    cout << res;

    return 0;
}