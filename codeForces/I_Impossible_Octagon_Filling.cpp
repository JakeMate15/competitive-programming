#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q; cin >> Q;
    while(Q--){
        long long a, k; 
        cin >> a >> k;
        long long p = (long long)floor(sqrt((long double)a));
        long long q, r;
        if(a <= p * (p + 1)){
            q = 2 * p - 1;
            r = a - p * p;
        } else {
            q = 2 * p;
            r = a - p * (p + 1);
        }
        long long t = q / 4;
        int rem = q % 4;
        long long T_right = t + (rem >= 1 ? 1 : 0);
        long long T_down  = t + (rem >= 2 ? 1 : 0);
        long long T_left  = t + (rem >= 3 ? 1 : 0);
        long long T_up    = t;
        long long sum_right = T_right * T_right;
        long long sum_down  = T_down * T_down;
        long long sum_left  = T_left * (T_left + 1);
        long long sum_up    = T_up * (T_up + 1);
        long long fx = sum_right - sum_left;
        long long fy = sum_up - sum_down;
        int d = q % 4;
        long long dx = 0, dy = 0;
        if(d == 0) { dx = 1; dy = 0; }
        else if(d == 1) { dx = 0; dy = -1; }
        else if(d == 2) { dx = -1; dy = 0; }
        else if(d == 3) { dx = 0; dy = 1; }
        long long finalX = fx + r * dx;
        long long finalY = fy + r * dy;
        long double dist = sqrt((long double)finalX * finalX + (long double)finalY * finalY);
        long double ans = dist * k;
        cout << fixed << setprecision(6) << (long double)ans << "\n";
    }
    return 0;
}
