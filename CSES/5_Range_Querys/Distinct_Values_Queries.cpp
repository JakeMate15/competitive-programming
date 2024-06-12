#include<bits/stdc++.h>

using namespace std;

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
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
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
    unordered_map<int, int> curr;

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