#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        __int128 T = 2;
        for(int i = 0; i < n; i++){
            char c1, c2; long long a, b;
            cin >> c1 >> a >> c2 >> b;
            if(c1 == '+' && c2 == '+'){
                T = T + a + b;
            } else if(c1 == '+' && c2 == 'x'){
                T = T * b + a;
            } else if(c1 == 'x' && c2 == '+'){
                T = T * a + b;
            } else {
                T = T * max((long long) a, (long long) b);
            }
        }
        // Convert __int128 T to string
        unsigned long long out[2] = {0, 0};
        bool neg = false;
        __int128 tmp = T < 0 ? -T : T;
        int idx = 0;
        while(tmp > 0){
            out[idx++] = (unsigned long long)(tmp % 10000000000000000000ULL);
            tmp /= 10000000000000000000ULL;
        }
        if(idx == 0) cout << 0 << "\n";
        else {
            if(idx == 2) cout << out[1];
            if(idx == 2){
                cout << setw(19) << setfill('0') << out[0] << "\n";
            } else {
                cout << out[0] << "\n";
            }
        }
    }
    return 0;
}
