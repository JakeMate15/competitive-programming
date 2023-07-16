//https://codeforces.com/contest/1846/problem/C
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
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

void sol(){
    int n,m,h;
    cin>>n>>m>>h;

    vector<pair<int,int>> a(n);
    forn(i,n){
        vi b(m);
        forn(j,m)   cin>>b[j];
        sort(all(b));
        int cur = 0;
        for(int x: b){
            cur+=x;
            if(cur<=h){
                a[i].first++;
                a[i].second+=cur;
            }
        }
    }

    forn(i,n)   a[i].second = (-a[i].second);
    int res = 1;
    forn(i,n)   if(a[i]>a[0])   res++;

    debug(res);
}

int main(){IO
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
}





/*
vector< pair<ll,int> > a(p);
    vector< map<> >

    ll aux = 0;
    forn(i,p){
        aux = 0;
        forn(j,np){
            ll lec;cin>>lec;
            aux+=lec;
        }
        a[i] = {aux,i};
    }

    sort(all(a));

    int i=1;
    for(auto x: a){
        if(x.second == 0)   break;
        i++;
    }

*/