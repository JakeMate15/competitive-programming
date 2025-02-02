#include <bits/stdc++.h>
using namespace std;

int main() {
    cerr << fixed << setprecision(10);
    vector<vector<int>> x(3,vector<int>(6));
    for(int i=0; i<3; i++) {
        for(int j=0; j<6; j++) cin >> x[i][j];
    }
    int ans = -1;
    long double best = 0;
    for(int i=0; i<3; i++) {
        bool flag = 1;
        vector<pair<int, int>> probs;
        for(int j=0; j<3; j++) {
            if(i == j) continue;
            int cnt = 0, cnt2 = 0;
            for(auto & val1 : x[i]) {
                for(auto & val2 : x[j]) {
                    
                    if (val1 == val2) continue;
                    cnt2++;
                    if(val1 > val2) cnt++;
                }
            }

            probs.emplace_back(cnt, cnt2);
            // cerr << i << ' ' << cnt << " " << cnt2 << "\n";     
            // cerr << (1.0 * cnt) / cnt2 << "\n";   
            // cerr << i 
            // cout << i << ' ' << j << ' ' << cnt << "\n";
            
            flag &= (cnt >= 18);
        }

        long double p1 = (1.0 * probs[0].first) / probs[0].second;
        long double p2 = (1.0 * probs[1].first) / probs[1].second;

        if (p1 >= 0.5 && p2 >= 0.5) {
            cout << i + 1 << "\n";
            return 0;
        }

        // long double curr = (1.0 * cnt) / 72.0;
        // if (curr > best && curr >= 0.5) {
        //     ans = i + 1;
        //     best = curr;
        
        // }

        // cerr << i << ' ' << cnt << " " << cnt2 << "\n";        
        // cerr << curr << "\n";

        // if(flag) {
        //     ans = i + 1;
        //     break;
        // }
    }

    // if(ans != -1) cout << ans << "\n";
    cout << "No dice\n";

}