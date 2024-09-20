#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, m, q;
        cin >> n >> m >> q;
        vector<ll> teachers(m);
        for(auto &x: teachers) cin >> x;
        sort(teachers.begin(), teachers.end());
        // Precompute min distance to 1 and to n
        ll min_b_to_1 = LLONG_MAX;
        ll min_b_to_n = LLONG_MAX;
        for(auto b: teachers){
            min_b_to_1 = min(min_b_to_1, abs(b - 1LL));
            min_b_to_n = min(min_b_to_n, abs(b - n));
        }
        // Read all queries first
        vector<ll> queries(q);
        for(auto &x: queries) cin >> x;
        // Process each query
        for(auto a_i: queries){
            // Binary search for minimal t
            ll left = 0;
            ll right = n;
            while(left < right){
                ll mid = left + (right - left)/2;
                ll L = a_i - mid;
                ll R = a_i + mid;
                L = max(1LL, L);
                R = min(n, R);
                ll current = L;
                bool covered = false;
                for(auto b_j: teachers){
                    ll start = b_j - mid;
                    ll end = b_j + mid;
                    start = max(1LL, start);
                //    end = min(n, end); // Not necessary for coverage
                    if(end < current){
                        continue;
                    }
                    if(start > current){
                        break;
                    }
                    current = max(current, end);
                    if(current >= R){
                        break;
                    }
                }
                if(current >= R){
                    right = mid;
                }
                else{
                    left = mid +1;
                }
            }
            cout << left << "\n";
        }
    }
}
