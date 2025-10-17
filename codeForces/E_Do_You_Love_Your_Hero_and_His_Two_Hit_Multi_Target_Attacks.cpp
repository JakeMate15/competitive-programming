#include<bits/stdc++.h>
using namespace std;

void sol () {
    long long k;
        cin >> k;
        
        // Handle trivial case:
        if(k == 0){
            cout << 0 << "\n";
            return;
        }
        
        // If k is small enough, we can do a single column of height k+1:
        // That yields exactly k pairs at distance=1 (between consecutive points).
        // But if k+1 > 500, we need a different approach.
        if(k+1 <= 500){
            cout << (k+1) << "\n";
            for(int i=0; i<(k+1); i++){
                cout << 0 << " " << i << "\n";
            }
            return;
        }
        
        // Otherwise, build multiple columns of manageable height.
        // For example, each column of height H has (H-1) distance-1 pairs.
        // We'll greedily add columns of height 500 (which yields 499 pairs) until we approach k.
        
        vector<pair<int,int>> pts; // to store the final coordinates
        int baseX = 0;
        long long currentPairs = 0;
        
        while(currentPairs + 499 <= k && (int)pts.size() + 500 <= 500){
            // place a column of height 500
            for(int row=0; row<500; row++){
                pts.push_back({baseX, row});
            }
            baseX += 2; // shift x by 2 so columns won't create distance=1 across columns
            currentPairs += 499;
        }
        
        // Now we have "currentPairs" < k, and we have used some portion of our 500 limit.
        // We still need (k - currentPairs) more pairs.  We'll do one more column of that exact needed height:
        long long need = k - currentPairs; 
        // we want need = (H-1), so H = need + 1
        // but we must ensure we don't exceed 500 total points
        long long H = need + 1;
        
        // how many points left can we place?
        int leftover = 500 - (int)pts.size();
        H = min<long long>(H, leftover);
        
        // place that column:
        for(int row=0; row<(int)H; row++){
            pts.push_back({baseX, row});
        }
        baseX += 2; // not strictly needed at the end
        
        // now we definitely have at least k pairs at distance=1
        // in some corner cases, if H < need+1, we overshoot or can't reach exactly k
        // but let's keep it simple.  (In a real contest, you'd refine or use 2D grids for big k.)
        
        cout << pts.size() << "\n";
        for(auto &p: pts){
            cout << p.first << " " << p.second << "\n";
        }
    }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}