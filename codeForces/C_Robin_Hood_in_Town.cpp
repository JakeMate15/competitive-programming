#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// https://github.com/alaneos777/reference/blob/master/queries.cpp
struct WaveletTree{
    int lo, hi;
    WaveletTree *left, *right;
    vector<int> freq;
    vector<ll> pref;

    WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int x, int y): lo(x), hi(y), left(nullptr), right(nullptr){
        if(from >= to) return;
        if(lo == hi){
            pref.reserve(to - from +1);
            pref.emplace_back(0);
            ll cumulative = 0;
            for(auto it = from; it != to; ++it){
                cumulative += *it;
                pref.emplace_back(cumulative);
            }
            return;
        }
        int m = lo + (hi - lo) / 2;
        auto f = [m](int x){return x <= m;};
        freq.reserve(to - from +1);
        freq.emplace_back(0);
        pref.reserve(to - from +1);
        pref.emplace_back(0);
        vector<int> left_data, right_data;
        for(auto it = from; it != to; ++it){
            if(f(*it)){
                freq.emplace_back(freq.back() + 1);
                pref.emplace_back(pref.back() + *it);
                left_data.emplace_back(*it);
            }
            else{
                freq.emplace_back(freq.back());
                pref.emplace_back(pref.back() + *it);
                right_data.emplace_back(*it);
            }
        }
        left = new WaveletTree(left_data.begin(), left_data.end(), lo, m);
        right = new WaveletTree(right_data.begin(), right_data.end(), m+1, hi);
    }

    ~WaveletTree(){
        if(left) delete left;
        if(right) delete right;
    }

    ll sum_first_k_smallest(int l, int r, int k){
        if(k == 0 || l > r) return 0;
        if(lo == hi){
            return (ll)lo * k;
        }
        int inLeft = freq[r] - freq[l-1];
        if(inLeft >= k){
            return left->sum_first_k_smallest(freq[l-1] +1, freq[r], k);
        }
        else{
            ll sumLeft = left ? left->sum_first_k_smallest(freq[l-1] +1, freq[r], inLeft) : 0;
            ll sumRight = right ? right->sum_first_k_smallest(l - freq[l-1], r - freq[r], k - inLeft) : 0;
            return sumLeft + sumRight;
        }
    }

    ll sum_query(int l, int r, int k){
        if(l > r || k < lo) return 0;
        if(hi <= k){
            return pref[r] - pref[l-1];
        }
        if(lo == hi){
            return (ll)lo * (r - l +1);
        }
        return (left ? left->sum_query(freq[l-1]+1, freq[r], k) : 0) + 
               (right ? right->sum_query(l - freq[l-1], r - freq[r], k) : 0);
    }
};

void sol () {
    int n, q;
    cin >> n >> q;

    int mn = INT32_MAX, mx = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    WaveletTree st(a.begin(), a.end(), mn, mx);
    while(q--){
        int l, r;
        cin >> l >> r;
        int m = r - l + 1;
        int k = (m + 1) /2; 

        ll sum_total = st.sum_query(l, r, mx);
        int x = m - k;
       
        ll sum_first_x = st.sum_first_k_smallest(l, r, x);
        
        ll sum_top_k = sum_total - sum_first_x;
        
        if(2LL * sum_top_k >= sum_total) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}
