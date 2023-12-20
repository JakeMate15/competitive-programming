#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;
typedef long long lli;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

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
				C[i][j] = A[i][j] + B[i][j];
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
		assert(n == B.m); //#columns of 1st matrix = #rows of 2nd matrix
		matrix<T> C(m, B.n);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < B.n; j++)
				for(int k = 0; k < n; k++)
					C[i][j] += A[i][k] * B[k][j];
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

};


template <typename T>
matrix<T> fastpow(matrix<T> A, int b) {
    matrix<T> ans = A;
    while(b){
        if(b & 1) ans *= A;
        b >>= 1;
        if(b) A *= A;
    }
    return ans;
}



void sol(){
    int n, m;
    cin >> n >> m;

    matrix<ld> mat(n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat.A[i][j];
        }
    }
    

    auto res = fastpow(mat, m - 1);
    for(int i = 0; i < n; i++) {
        cout << res.A[0][i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(14);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}