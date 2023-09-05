//TLE case 22

#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)      	cout << a << "\n"
#define deb(a)        	cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9+7;
const int mx = 1e9;

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y,j;
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const ld & k) const{return point(x * k, y * k);}
	point operator/(const ld & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	point rotate(const ld & a) const{return point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));}
	point perp() const{return point(-y, x);}
	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}
	ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}
	ld norm() const{return x * x + y * y;}
	ld length() const{return sqrtl(x * x + y * y);}
	point unit() const{return (*this) / length();}

	bool operator==(const point & p) const{return eq(x, p.x) && eq(y, p.y);}
	bool operator!=(const point & p) const{return !(*this == p);}
	bool operator<(const point & p) const{return le(x, p.x) || (eq(x, p.x) && le(y, p.y));}
	bool operator>(const point & p) const{return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y));}
	bool half(const point & p) const{return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0));}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

map<int,int> convexHull(vector<point> P){
	sort(P.begin(), P.end());
	vector<point> L, U;
    map<int,int> res;
	for(int i = 0; i < P.size(); i++){
		while(L.size() >= 2 && le((L[L.size() - 2] - P[i]).cross(L[L.size() - 1] - P[i]), 0)){
            res[L.back().j]--;
			L.pop_back();
		}
		L.push_back(P[i]);
        res[P[i].j]++;
	}
	for(int i = P.size() - 1; i >= 0; i--){
		while(U.size() >= 2 && le((U[U.size() - 2] - P[i]).cross(U[U.size() - 1] - P[i]), 0)){
			res[U.back().j]--;
            U.pop_back();
		}
		U.push_back(P[i]);
        res[P[i].j]++;
	}

	return res;
}

bool cmp(point a, point b){
    return a.j<b.j;
}

void sol(){
    int n;
    cin>>n;

    vector<point> puntos(n);
    forn(i,n){
        cin>>puntos[i];
        puntos[i].j = i+1;
    }

    map<int,int> ch = convexHull(puntos);

    /*
    int ant = -1;
    for(auto x: ch){
        if(x==ant)  continue;
        deb(x);
        ant = x;
    }
    */

    for(auto &[a,b]:ch){
        if(b>0) deb(a);
    }

}

int main(){

	int t=1;
	//cin>>t;
	while(t--){
		sol();
	}

	return 0;
}