#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void sol(){
    int n;
    cin >> n;

    vector<ll> a(n);
    a[0] = 2;
    a[1] = 3;

    forr(i,2,n) {
        a[i] = a[i-1] + 1;
        while((a[i]* 3) % (a[i - 1] + a[i - 2]) == 0){
            a[i]++;
        }
    }

    for(auto x: a) {
        deb(x);
    }

    debln("");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
