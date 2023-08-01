#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()


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

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}


vector<point> intersectionCircles(const point & c1, ld r1, const point & c2, ld r2){
	//circle 1 with center c1 and radius r1
	//circle 2 with center c2 and radius r2
	point d = c2 - c1;
	ld d2 = d.norm();
	if(eq(d2, 0)) return {}; //concentric circles
	ld pd = (d2 + r1*r1 - r2*r2) / 2;
	ld h2 = r1*r1 - pd*pd/d2;
	point p = c1 + d*pd/d2;
	if(eq(h2, 0)) return {p}; //circles touch at one point
	else if(le(h2, 0)) return {}; //circles don't intersect
	else{
		point u = d.perp() * sqrt(h2/d2);
		return {p - u, p + u};
	}
}

void sol(){
        int radio,d,n;
        cin>>radio>>d>>n;

        /*
        //int diametro = radio*2;
        int corteza = d;
        point centro(0,0);

        int n;
        cin>>n;


        fore(i,1,n){
                point cC;
                int rC;
                cin>>cC>>rC;
                
                cout << "Caso " << i << endl;;

                vector<point> intPizza,intCorteza;
                intPizza = intersectionCircles(centro,radio,cC,rC);
                intCorteza = intersectionCircles(centro,corteza,cC,rC);

                cout << sz(intPizza) << " " << sz(intCorteza) << endl;

                /*
                cout << "Interseccion con pizza: " << sz(intPizza) << endl;
                for(auto x: intPizza){
                        cout << x << " ";
                }
                debug("");
                

                /*
                cout << "Interseccion con pizza: " << sz(intCorteza) << endl;
                for(auto x: intCorteza){
                        cout << x << " ";
                }
                debug("");
                
        }
        */

        int res =0;

        while(n--){
                int x,y,r;
                cin>>x>>y>>r;
                int l2 = x*x + y*y;

                bool a,b,c;
                a = r*2<=d;
                //cout << a << " " << r*2 << endl;
                b = l2>=(radio+r-d)*(radio+r-d);
                //cout << b << " " << (radio+r-d)*(radio+r-d)<< endl;
                c = l2<=(radio-r)*(radio-r);
                //cout << b << " " << (radio-r)*(radio-r) << endl;

                if(a&b&c)       res++;
        }

        debug(res);

}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}