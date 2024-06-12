#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld PI = acos(-1.0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    auto f = [] (ld a, ld l, ld r) -> ld {
        return (PI * l / 3.0) * (3.0 * l * r * cos(a) * sin(a) + (3.0 * r * r) * sin(a) + l * l * sin(a) * cos(a) * cos(a));
    };
    
    for(int i = 0; i < n; i++){
        int c,d;
        cin >> c >> d;
        ld l = c, r = d;

        ld lo = 0.0, hi = PI / 2.0;
        for(int i = 0; i < 50; i++){
            ld m1 = lo + (hi - lo) / 3.0;
            ld m2 = hi - (hi - lo) / 3.0;

            if(f(m1, l, r) < f(m2, l, r))
                lo = m1;
            else
                hi = m2;
        }

        cout << fixed << setprecision(8) << PI - lo <<'\n';
    }
}