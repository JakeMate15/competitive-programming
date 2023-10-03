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

void sol(int t){
    int l, r, x, a ,b;
    cin >> l >> r >> x >> a >> b;

    if(a == b) {
        debln(0);
    }
    else if(abs(a - b) >= x) {
        debln(1);
    }
    else if((abs(a - l) >= x && abs(l - b) >= x) || (abs(a - r) >= x && abs(r - b) >= x)) {
        debln(2);
    }
    else if(abs(a - r) >= x && abs(r - l) >= x && abs(l - b) >= x) {
        debln(3);
    }
    else if(abs(a - l) >= x && abs(l - r) >= x && abs(r - b) >= x) {
        debln(3);
    }
    else{
        debln(-1);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    fore(i, 1, t){
        sol(i);
    }

    return 0;
}