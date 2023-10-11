#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;
typedef long double ld;

struct point{
    int x = 0;
    int y = 0;
};

ld distance(const point &a, const point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

void sol(){
    point casa, trabajo, l1, l2;

    cin >> casa.x >> casa.y >> l1.x >> l1.y >> l2.x >> l2.y;

    ld res = min({
        max(distance(l1, casa), distance(l1, trabajo)),
        max(distance(l2, casa), distance(l2, trabajo)),
        max({distance(trabajo, l1), distance(l1, l2) / 2, distance(l2, casa)}),
        max({distance(trabajo, l2), distance(l1, l2) / 2, distance(l1, casa)})
    });

    debln(res);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}