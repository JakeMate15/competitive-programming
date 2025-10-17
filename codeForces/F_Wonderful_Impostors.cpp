//~ mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1300*1007;
const ll inf=1e9;
int n1;

int n, m;

int typ[nax];
pii prz[nax];

int q;
pii zap[nax];

int zas[nax];

ll narz[nax];
ll pod[nax];

ll daj(int v)
{
	return narz[v]+pod[v];
}

void upd(int v)
{
	pod[v]=min(daj(2*v), daj(2*v+1));
}

void pisz(int v, int a, int b, int graa, int grab, ll w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

ll czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return daj(v);
	}
	if (a>grab || b<graa)
	{
		return inf;
	}
	return min(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	)+narz[v];
}

int szukpie(int v, int a, int b, ll conaj)
{
	if (daj(v)>conaj)
		return inf;
	if (a==b)
		return a;
	conaj-=narz[v];
	if (daj(2*v)<=conaj)
		return szukpie((v<<1), a, (a+b)>>1, conaj);
	return szukpie((v<<1)^1, (a+b+2)>>1, b, conaj);
}

int szukost(int v, int a, int b, ll conaj)
{
	if (daj(v)>conaj)
		return 0;
	if (a==b)
		return a;
	conaj-=narz[v];
	if (daj(2*v+1)<=conaj)
		return szukost((v<<1)^1, (a+b+2)>>1, b, conaj);
	return szukost((v<<1), a, (a+b)>>1, conaj);
}

int wsk;

multiset<int> setel[nax];
int mini[nax];

int znajdz(int v, int a, int b, int conaj)
{
	if (a>=conaj)
	{
		return mini[v];
	}
	if (b<conaj)
	{
		return inf;
	}
	return min(
		znajdz((v<<1), a, (a+b)>>1, conaj),
		znajdz((v<<1)^1, (a+b+2)>>1, b, conaj)
	);
}

int best(multiset<int> &on)
{
	if (on.empty())
		return inf;
	return *on.begin();
}

void ogar(int v)
{
	mini[v+n1-1]=best(setel[v]);
	v+=n1-1;
	v>>=1;
	while(v)
	{
		mini[v]=min(mini[2*v], mini[2*v+1]);
		v>>=1;
	}
}

void usun()
{
	int l=prz[wsk].first;
	int r=prz[wsk].second;
	if (!typ[wsk])
	{
		pisz(1, 1, n1, l, r, -1);
	}
	else
	{
		setel[l].erase(setel[l].find(r));
		ogar(l);
	}
	wsk++;
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d%d%d", &typ[i], &prz[i].first, &prz[i].second);
	n1=1;
	while(n1<=n)
		n1<<=1;
	
	for (int i=1; i<2*n1; i++)
	{
		narz[i]=0;
		pod[i]=0;
		setel[i].clear();
		mini[i]=inf;
	}
	
	for (int i=1; i<=m; i++)
		zas[i]=0;
	
	wsk=1;
	for (int i=1; i<=m; i++)
	{
		int l=prz[i].first;
		int r=prz[i].second;
		if (!typ[i])
		{
			pisz(1, 1, n1, l, r, 1);
			while(1)
			{
				pisz(1, 1, n1, 1, l-1, 1);
				int pra=szukpie(1, 1, n1, 0);
				pisz(1, 1, n1, 1, l-1, -1);
				
				pisz(1, 1, n1, r+1, n1, 1);
				int lew=szukost(1, 1, n1, 0);
				pisz(1, 1, n1, r+1, n1, -1);
				
				//~ debug() << imie(i) << imie(lew) << imie(pra);
				
				if (znajdz(1, 1, n1, lew+1)<pra)
					usun();
				else
					break;
			}
		}
		else
		{
			setel[l].insert(r);
			ogar(l);
			
			while(czyt(1, 1, n1, l, r)>0)
				usun();
		}
		zas[i]=wsk;
	}
	//~ debug() << range(zas+1, zas+1+m);
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (zas[b]<=a)
			printf("YES\n");
		else
			printf("NO\n");
	}
	//~ exit(0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
