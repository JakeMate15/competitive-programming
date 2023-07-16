#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y;
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

struct circulo {
    point centro;
    long double radio;

    circulo(long double x, long double y, long double radio) : centro(x, y), radio(radio) {}
};

bool intersectionCircles(const circulo & cir1, const circulo & cir2){
    point c1 = cir1.centro, c2 = cir2.centro;
    ld r1 = cir1.radio, r2 = cir2.radio;
	//circle 1 with center c1 and radius r1
	//circle 2 with center c2 and radius r2
	point d = c2 - c1;
	ld d2 = d.norm();
	if(eq(d2, 0))       return true; //concentric circles
	ld pd = (d2 + r1*r1 - r2*r2) / 2;
	ld h2 = r1*r1 - pd*pd/d2;
	point p = c1 + d*pd/d2;
	if(eq(h2, 0))       return true; //circles touch at one point
	else if(le(h2, 0))  return false; //circles don't intersect
	else                return true;
}

struct UnionFind {
  int n;
  vector<int> dad, size;
 
  UnionFind(int N) : n(N), dad(N), size(N, 1) {
    while (N--) dad[N] = N;
  }
  // 4
  // O(lg*(N))
  int root(int u) {
    if (dad[u] == u) return u;
    return dad[u] = root(dad[u]);
  }
  // 8
  // O(1)
  void join(int u, int v) {
    int Ru = root(u), Rv = root(v);
    if (Ru == Rv) return;
    if (size[Ru] > size[Rv]) swap(Ru, Rv);
    --n, dad[Ru] = Rv;
    size[Rv] += size[Ru];
  }
  // 4
  // O(lg*(N))
  bool areConnected(int u, int v) {
    return root(u) == root(v);
  }
  // 4
  int getSize(int u) { return size[root(u)]; }
 
  int numberOfSets() { return n; }
};

void sol(){
    int n,w,l;
    cin>>n>>w>>l;

    vector<circulo> a;
    forn(i,n){
        ld cx,cy,cr;
        cin>>cx>>cy>>cr;

        a.emplace_back(cx, cy, cr);
    }

    UnionFind ds(5);
    ds.insert(2);
    ds.insert(3);
    ds.insert(5);


}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}