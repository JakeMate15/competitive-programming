#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
struct Query {
    int L, R, index;
};
 
bool compare(Query a, Query b) {
    static int block_size = sqrt(10000);
    if (a.L / block_size != b.L / block_size)
        return a.L / block_size < b.L / block_size;
    return a.R < b.R;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cin >> Q;
    
    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].L >> queries[i].R;
        --queries[i].L;
        --queries[i].R; 
        queries[i].index = i;
    }
    
    sort(queries.begin(), queries.end(), compare);
    
    vector<int> res(Q);
    int cL = 0, cR = -1;
    gp_hash_table<int, int, custom_hash> curr;
 
    auto add = [&](int pos) {
        curr[A[pos]]++;
    };
    
    auto remove = [&](int pos) {
        curr[A[pos]]--;
        if (curr[A[pos]] <= 0) 
            curr.erase(A[pos]); 
    };
    
    auto get = [&]() {
        return curr.size();
    };
    
    for (auto& query : queries) {
        while (cR < query.R) add(++cR);
        while (cR > query.R) remove(cR--);
        while (cL < query.L) remove(cL++);
        while (cL > query.L) add(--cL);
        res[query.index] = get();
    }
    
    for (int i = 0; i < Q; ++i) {
        cout << res[i] << '\n';
    }
 
    return 0;
}


vector<pair<int, int>> arr(n);
for (auto x: arr) {
    
}