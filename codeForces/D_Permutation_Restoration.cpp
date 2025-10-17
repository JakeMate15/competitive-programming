#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        cerr << "si\n";
    #endif
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> b(n+1);
        
        for(int i = 1; i <= n; i++)
            cin>>b[i];
            
        vector<int> L(n + 1), R(n + 1);
        for(int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                L[i] = i + 1; 
                R[i] = n;
            } else {
                L[i] = i / (b[i] + 1) + 1;
                R[i] = i / b[i];
            }
        }
        
        vector<int> ans(n + 1, 0);
        vector<vector<int>> add(n + 2);
        for(int i = 1; i <= n; i++) {
            if(L[i] >= 1 && L[i] <= n)
            add[L[i]].push_back(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for(int x = 1; x <= n; x++) {
            for(auto i: add[x]) {
                pq.push({R[i], i});
            }
            auto pr = pq.top();
            pq.pop();
            ans[pr.second] = x;
        }
        
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << (i == n ? "\n" : " ");
        }
    }
            
    return 0;
}
