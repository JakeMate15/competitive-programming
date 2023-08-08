#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define lli long long
#define MAXN 100100
#define MX 1e18

lli n, m, v;
lli s, e;

set<lli> escalera, elevador;

lli bs(set<lli> &cs, lli ov) {

	auto it = cs.lower_bound(ov);
	if (it == cs.end()) return MX;
	return *it;

}

lli bs2(set<lli> &cs, lli ov) {

	if (!cs.size()) return -MX;
	auto it = cs.lower_bound(ov);
	if (it == cs.begin()) return -MX;
	it--;
	return *it;

}

lli ceil(lli x, lli y) {
	lli res = x / y;
	if (x % y) res++;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	scanf("%lld%lld", &n, &m);
	scanf("%lld%lld", &s, &e);
	scanf("%lld", &v);

	for (int i = 0; i < s; i++) {
		lli cv; scanf("%lld", &cv);
		escalera.insert(cv);
	}

	for (int i = 0; i < e; i++) {
		lli cv; scanf("%lld", &cv);
		elevador.insert(cv);
	}

	int q; scanf("%d", &q);
	while (q--) {

		lli x1, y1, a, b;
		scanf("%lld%lld%lld%lld", &x1, &y1, &a, &b);

		if (x1 == a) {
			printf("%lld\n", abs(b - y1));
			continue;
		}

		lli a1 = bs(escalera, y1);
		lli a2 = bs2(escalera, y1);

		lli res = MX;
		res = min(res, abs(y1 - a1) + abs(b - a1) + abs(x1 - a));
		res = min(res, abs(y1 - a2) + abs(b - a2) + abs(x1 - a));

		a1 = bs(escalera, b);
		a2 = bs2(escalera, b);

		res = min(res, abs(y1 - a1) + abs(b - a1) + abs(x1 - a));
		res = min(res, abs(y1 - a2) + abs(b - a2) + abs(x1 - a));

		a1 = bs(elevador, y1);
		a2 = bs2(elevador, y1);

		res = min(res, abs(y1 - a1) + abs(b - a1) + ceil(abs(x1 - a), v));
		res = min(res, abs(y1 - a2) + abs(b - a2) + ceil(abs(x1 - a), v));

		a1 = bs(elevador, b);
		a2 = bs2(elevador, b);

		res = min(res, abs(y1 - a1) + abs(b - a1) + ceil(abs(x1 - a), v));
		res = min(res, abs(y1 - a2) + abs(b - a2) + ceil(abs(x1 - a), v));

		printf("%lld\n", res);

	}
	
}