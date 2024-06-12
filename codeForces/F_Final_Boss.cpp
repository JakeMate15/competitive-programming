#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long h, n;
        cin >> h >> n;
        
        vector<long long> damage(n);
        vector<long long> cooldown(n);
        
        for (long long i = 0; i < n; ++i) {
            cin >> damage[i];
        }
        
        for (long long i = 0; i < n; ++i) {
            cin >> cooldown[i];
        }
        
        // Priority queue to manage which attacks are available and when
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        
        // Initially, all attacks are available at turn 0
        for (long long i = 0; i < n; ++i) {
            pq.push({0, i});
        }
        
        long long turns = 0;
        long long currentHealth = h;
        
        while (currentHealth > 0) {
            turns++;
            long long attacksThisTurn = 0;
            vector<pair<long long, long long>> nextAttacks;
            
            // Use all available attacks this turn
            while (!pq.empty() && pq.top().first <= turns) {
                auto [availableTurn, attackIdx] = pq.top();
                pq.pop();
                currentHealth -= damage[attackIdx];
                nextAttacks.push_back({turns + cooldown[attackIdx], attackIdx});
                attacksThisTurn++;
            }
            
            // If no attacks were available this turn, increase turn counter
            if (attacksThisTurn == 0) {
                if (!pq.empty()) {
                    turns = pq.top().first - 1;
                }
            } else {
                for (auto &attack : nextAttacks) {
                    pq.push(attack);
                }
            }
        }
        
        cout << turns << "\n";
    }
    
    return 0;
}
