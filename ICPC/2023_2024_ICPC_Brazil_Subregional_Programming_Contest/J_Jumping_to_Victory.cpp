#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

ld eps = 1e-9, inf = numeric_limits<ld>::max(), inf_coord = 1e9;

bool geq(ld a, ld b) { return a - b >= -eps; }    // a >= b
bool leq(ld a, ld b) { return b - a >= -eps; }    // a <= b
bool ge(ld a, ld b) { return a - b > eps; }       // a > b
bool le(ld a, ld b) { return b - a > eps; }       // a < b
bool eq(ld a, ld b) { return abs(a - b) <= eps; } // a == b
bool neq(ld a, ld b) { return abs(a - b) > eps; } // a != b

struct point {
    ld x, y;
    int idx = -1;
    point() {}
    point(ld x, ld y) : x(x), y(y) {}

    point operator+(const point &p) const { return point(x + p.x, y + p.y); }

    point operator-(const point &p) const { return point(x - p.x, y - p.y); }

    point operator*(ld k) const { return point(x * k, y * k); }

    point operator/(ld k) const { return point(x / k, y / k); }

    ld dot(const point &p) const { return x * p.x + y * p.y; }

    ld cross(const point &p) const { return x * p.y - y * p.x; }

    ld norm() const { return x * x + y * y; }

    ld length() const { return sqrtl(x * x + y * y); }

    point unit() const { return (*this) / length(); }

    point perpendicular() const { return point(-y, x); }

    bool operator<(const point &p) const {
        if (eq(x, p.x))
            return le(y, p.y);
        return le(x, p.x);
    }

    bool operator>(const point &p) const {
        if (eq(x, p.x))
            return ge(y, p.y);
        return ge(x, p.x);
    }

    bool operator==(const point &p) const { return eq(x, p.x) && eq(y, p.y); }

    bool operator!=(const point &p) const { return !(*this == p); }
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

int sgn(ld x) {
    if (ge(x, 0))
        return 1;
    if (le(x, 0))
        return -1;
    return 0;
}

vector<point> convexHull(vector<point> P, bool collineal = false) {
    auto cmp = leq;
    if (collineal)
        cmp = le;
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    if (P.size() <= 2)
        return P;
    vector<point> L, U;
    for (int i = 0; i < sz(P); i++) {
        while (L.size() >= 2 &&
               cmp((L[L.size() - 2] - P[i]).cross(L[L.size() - 1] - P[i]), 0)) {
            L.pop_back();
        }
        L.push_back(P[i]);
    }
    for (int i = sz(P) - 1; i >= 0; i--) {
        while (U.size() >= 2 &&
               cmp((U[U.size() - 2] - P[i]).cross(U[U.size() - 1] - P[i]), 0)) {
            U.pop_back();
        }
        U.push_back(P[i]);
    }
    L.pop_back();
    U.pop_back();
    L.insert(L.end(), U.begin(), U.end());
    return L;
}

point intersectLines(const point &a1, const point &v1, const point &a2,
                     const point &v2) {
    ld det = v1.cross(v2);
    return a1 + v1 * ((a2 - a1).cross(v2) / det);
}

int intersectLineSegmentInfo(const point &a, const point &v, const point &c,
                             const point &d) {
    point v2 = d - c;
    ld det = v.cross(v2);
    if (eq(det, 0)) {
        if (eq((c - a).cross(v), 0)) {
            return -1; // infinity points
        } else {
            return 0; // no point
        }
    } else {
        return sgn(v.cross(c - a)) !=
               sgn(v.cross(d - a)); // 1: single point, 0: no point
    }
}

pair<point, ld> getCircle(const point &m, const point &n, const point &p) {
    point c = intersectLines((n + m) / 2, (n - m).perpendicular(), (p + n) / 2,
                             (p - n).perpendicular());
    ld r = (c - m).length();
    return {c, r};
}

const point inf_pt(inf, inf);

struct QuadEdge {
    point origin;
    QuadEdge *rot = nullptr;
    QuadEdge *onext = nullptr;
    bool used = false;
    QuadEdge *rev() const { return rot->rot; }
    QuadEdge *lnext() const { return rot->rev()->onext->rot; }
    QuadEdge *oprev() const { return rot->onext->rot; }
    point dest() const { return rev()->origin; }
};

QuadEdge *make_edge(const point &from, const point &to) {
    QuadEdge *e1 = new QuadEdge;
    QuadEdge *e2 = new QuadEdge;
    QuadEdge *e3 = new QuadEdge;
    QuadEdge *e4 = new QuadEdge;
    e1->origin = from;
    e2->origin = to;
    e3->origin = e4->origin = inf_pt;
    e1->rot = e3;
    e2->rot = e4;
    e3->rot = e2;
    e4->rot = e1;
    e1->onext = e1;
    e2->onext = e2;
    e3->onext = e4;
    e4->onext = e3;
    return e1;
}

void splice(QuadEdge *a, QuadEdge *b) {
    swap(a->onext->rot->onext, b->onext->rot->onext);
    swap(a->onext, b->onext);
}

void delete_edge(QuadEdge *e) {
    splice(e, e->oprev());
    splice(e->rev(), e->rev()->oprev());
    delete e->rev()->rot;
    delete e->rev();
    delete e->rot;
    delete e;
}

QuadEdge *connect(QuadEdge *a, QuadEdge *b) {
    QuadEdge *e = make_edge(a->dest(), b->origin);
    splice(e, a->lnext());
    splice(e->rev(), b);
    return e;
}

bool left_of(const point &p, QuadEdge *e) {
    return ge((e->origin - p).cross(e->dest() - p), 0);
}

bool right_of(const point &p, QuadEdge *e) {
    return le((e->origin - p).cross(e->dest() - p), 0);
}

#define i128 __int128_t
i128 det3(i128 a1, i128 a2, i128 a3, i128 b1, i128 b2, i128 b3, i128 c1,
          i128 c2, i128 c3) {
    return a1 * (b2 * c3 - c2 * b3) - a2 * (b1 * c3 - c1 * b3) +
           a3 * (b1 * c2 - c1 * b2);
}

bool in_circle(const point &a, const point &b, const point &c, const point &d) {
    i128 det =
        -det3(b.x, b.y, b.norm(), c.x, c.y, c.norm(), d.x, d.y, d.norm());
    det += det3(a.x, a.y, a.norm(), c.x, c.y, c.norm(), d.x, d.y, d.norm());
    det -= det3(a.x, a.y, a.norm(), b.x, b.y, b.norm(), d.x, d.y, d.norm());
    det += det3(a.x, a.y, a.norm(), b.x, b.y, b.norm(), c.x, c.y, c.norm());
    return det > 0;
}

pair<QuadEdge *, QuadEdge *> build_tr(int l, int r, vector<point> &P) {
    if (r - l + 1 == 2) {
        QuadEdge *res = make_edge(P[l], P[r]);
        return make_pair(res, res->rev());
    }
    if (r - l + 1 == 3) {
        QuadEdge *a = make_edge(P[l], P[l + 1]), *b = make_edge(P[l + 1], P[r]);
        splice(a->rev(), b);
        int sg = sgn((P[l + 1] - P[l]).cross(P[r] - P[l]));
        if (sg == 0)
            return make_pair(a, b->rev());
        QuadEdge *c = connect(b, a);
        if (sg == 1)
            return make_pair(a, b->rev());
        else
            return make_pair(c->rev(), c);
    }
    int mid = (l + r) / 2;
    QuadEdge *ldo, *ldi, *rdo, *rdi;
    tie(ldo, ldi) = build_tr(l, mid, P);
    tie(rdi, rdo) = build_tr(mid + 1, r, P);
    while (true) {
        if (left_of(rdi->origin, ldi)) {
            ldi = ldi->lnext();
            continue;
        }
        if (right_of(ldi->origin, rdi)) {
            rdi = rdi->rev()->onext;
            continue;
        }
        break;
    }
    QuadEdge *basel = connect(rdi->rev(), ldi);
    auto valid = [&basel](QuadEdge *e) { return right_of(e->dest(), basel); };
    if (ldi->origin == ldo->origin)
        ldo = basel->rev();
    if (rdi->origin == rdo->origin)
        rdo = basel;
    while (true) {
        QuadEdge *lcand = basel->rev()->onext;
        if (valid(lcand)) {
            while (in_circle(basel->dest(), basel->origin, lcand->dest(),
                             lcand->onext->dest())) {
                QuadEdge *t = lcand->onext;
                delete_edge(lcand);
                lcand = t;
            }
        }
        QuadEdge *rcand = basel->oprev();
        if (valid(rcand)) {
            while (in_circle(basel->dest(), basel->origin, rcand->dest(),
                             rcand->oprev()->dest())) {
                QuadEdge *t = rcand->oprev();
                delete_edge(rcand);
                rcand = t;
            }
        }
        if (!valid(lcand) && !valid(rcand))
            break;
        if (!valid(lcand) ||
            (valid(rcand) && in_circle(lcand->dest(), lcand->origin,
                                       rcand->origin, rcand->dest())))
            basel = connect(rcand, basel->rev());
        else
            basel = connect(basel->rev(), lcand->rev());
    }
    return make_pair(ldo, rdo);
}

vector<vector<point>> delaunay(vector<point> P) {
    sort(all(P));
    auto res = build_tr(0, (int)P.size() - 1, P);
    QuadEdge *e = res.first;
    vector<QuadEdge *> edges = {e};
    while (le(
        (e->dest() - e->onext->dest()).cross(e->origin - e->onext->dest()), 0))
        e = e->onext;
    auto add = [&P, &e, &edges]() {
        QuadEdge *curr = e;
        do {
            curr->used = true;
            P.push_back(curr->origin);
            edges.push_back(curr->rev());
            curr = curr->lnext();
        } while (curr != e);
    };
    add();
    P.clear();
    int kek = 0;
    while (kek < (int)edges.size())
        if (!(e = edges[kek++])->used)
            add();
    vector<vector<point>> ans;
    for (int i = 0; i < (int)P.size(); i += 3) {
        ans.push_back({P[i], P[i + 1], P[i + 2]});
    }
    return ans;
}

vector<vector<point>> voronoi(vector<point> P) {
    vector<vector<point>> cells(P.size());
    for (int i = 0; i < sz(P); i++) { 
		P[i].idx = i; 
	}

    auto ch = convexHull(P);
    if (ch.size() > 2) {
        auto dt = delaunay(P);

        for (auto &tri : dt) {
            point c = getCircle(tri[0], tri[1], tri[2]).first;
            for (auto &p : tri) {
                cells[p.idx].push_back(c);
            }
        }

        ch = convexHull(P, true); // with collineal
        for (int i = 0; i < sz(ch); i++) {
            point &a = ch[i];
            point &b = ch[(i + 1) % ch.size()];
            point mit = (a + b) / 2;
            point c = (mit + (a - mit).perpendicular().unit() * inf_coord);

            cells[a.idx].push_back(c);
            cells[b.idx].push_back(c);
        }
    } else if (ch.size() == 2) {
        sort(all(P));

        cells[P[0].idx].emplace_back(-inf_coord, -inf_coord);
        cells[P.back().idx].emplace_back(inf_coord, inf_coord);

        for(int i = 0; i < sz(P) - 1; i++) {
            point mit = (P[i + 1] - P[i]) / 2;
            point a = (mit - (P[i] - mit).perpendicular().unit() * inf_coord);
            point b = (mit - (P[i] - mit).perpendicular().unit() * -inf_coord);

            for(int j = 0; j < 2; j++) {
                cells[P[i + j].idx].push_back(a);
                cells[P[i + j].idx].push_back(b);
            }
        }
    } else {
        cells[0] = {
            {inf_coord, inf_coord},
            {-inf_coord, inf_coord},
            {-inf_coord, -inf_coord},
            {inf_coord, -inf_coord},
        };
    }

    for (auto &cell : cells) {
        cell = convexHull(cell);
    }

    return cells;
}

bool puntoDentroRectangulo(const point& p, const point& topLeft, const point& bottomRight) {
    return p.x >= topLeft.x && p.x <= bottomRight.x && p.y >= topLeft.y && p.y <= bottomRight.y;
}

ld distanciaEntrePuntos(const point& p1, const point& p2) {
    ld dx = p2.x - p1.x;
    ld dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

vector<point> cutPolygon(const vector<point> & P, const point & a, const point & v){
	//returns the part of the convex polygon P on the left side of line a+tv
	int n = P.size();
	vector<point> lhs;
	for(int i = 0; i < n; ++i){
		if(geq(v.cross(P[i] - a), 0)){
			lhs.push_back(P[i]);
		}
		if(intersectLineSegmentInfo(a, v, P[i], P[(i+1)%n]) == 1){
			point p = intersectLines(a, v, P[i], P[(i+1)%n] - P[i]);
			if(p != P[i] && p != P[(i+1)%n]){
				lhs.push_back(p);
			}
		}
	}
	return lhs;
}

bool pointInLine(const point & a, const point & v, const point & p){
	//line a+tv, point p
	return eq((p - a).cross(v), 0);
}

bool pointInSegment(const point & a, const point & b, const point & p){
	//segment ab, point p
	return pointInLine(a, b - a, p) && leq((a - p).dot(b - p), 0);
}

bool pointInPerimeter(const vector<point> & P, const point & p){
	int n = P.size();
	for(int i = 0; i < n; i++){
		if(pointInSegment(P[i], P[(i + 1) % n], p)){
			return true;
		}
	}
	return false;
}

bool crossesRay(const point & a, const point & b, const point & p){
	return (geq(b.y, p.y) - geq(a.y, p.y)) * sgn((a - p).cross(b - p)) > 0;
}

int pointInPolygon(const vector<point> & P, const point & p){
	if(pointInPerimeter(P, p)){
		return -1;
	}
	int n = P.size();
	int rays = 0;
	for(int i = 0; i < n; i++){
		rays += crossesRay(P[i], P[(i + 1) % n], p);
	}
	return rays & 1; //0: point outside, 1: point inside
}

ld distancePointLine(const point & a, const point & v, const point & p){
	//line: a + tv, point p
	return abs(v.cross(p - a)) / v.length();
}

void sol(){
	vector<point> rec(4);
	for(int i = 0; i < 4; i++) {
		int x, y;
		cin >> x >> y;
		rec[i] = point(x,y);
	}

	auto rect = convexHull(rec, 1);

	int n;
	cin >> n;
	vector<point> j(n);

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		j[i] = point(x, y);
	}

	auto v = voronoi(j);

	for(int i = 0; i < sz(v); i++) {
        v[i] = cutPolygon(v[i], rect[0], rect[1] - rect[0]);
        v[i] = cutPolygon(v[i], rect[1], rect[2] - rect[1]);
        v[i] = cutPolygon(v[i], rect[2], rect[3] - rect[2]);
        v[i] = cutPolygon(v[i], rect[3], rect[0] - rect[3]);

		// v[i] = cutPolygon(v[i], rect[1], rect[0] - rect[1]);
		// v[i] = cutPolygon(v[i], rect[3], rect[1] - rect[3]);
		// v[i] = cutPolygon(v[i], rect[2], rect[3] - rect[2]);
		// v[i] = cutPolygon(v[i], rect[0], rect[2] - rect[0]);
	}

	// for(auto celda: v) {
	// 	cerr << "Nueva celda \n";
	// 	for(auto p: celda) {
	// 		cerr << p.x << " " << p.y << "\n";
	// 	}
	// }

	ld res = 0.0;

	int i = 0;
	for(auto c: v) {
		// cerr << "nvo\n";

		for(point p: c) {
			// cerr << p << "\n";
			if(pointInPolygon(rect, p)) {
				ld curr = distanciaEntrePuntos(p, j[i]);
                
				if(ge(curr, res)) {
					res = curr;
				}
			}
		}
		i++;
	}

	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed << setprecision(12);

	int t=1;
	//cin>>t;

	while(t--){
		sol();
	}

	return 0;
}