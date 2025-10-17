#include<bits/stdc++.h>
using namespace std;

const int INF = 1E9;

void sol () {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    vector<int> L(n + 1, -1), R(n + 1, -1);
    {
        vector<int> st;
        for (int j = 1; j <= n; j++) {
            while (!st.empty() && a[st.back()] <= a[j]) 
                st.pop_back();
            L[j] = st.empty() ? -1 : st.back();
            st.push_back(j);
        }
    }

    {
        vector<int> st;
        for (int j = n; j >= 1; j--) {
            while (!st.empty() && a[st.back()] >= a[j]) 
                st.pop_back();
            R[j] = st.empty() ? -1 : st.back();
            st.push_back(j);
        }
    }

    vector<vector<int>> b(n + 1);
    for (int j = 1; j <= n; j++) {
        if (L[j] != -1 && R[j] != -1) 
            b[L[j]].push_back(R[j]);
    }

    vector<int> bad(n + 2, INF);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int l = n; l >= 1; l--) {
        for (int rval : b[l]) 
            pq.push(rval);
        bad[l] = pq.empty() ? INF : pq.top();
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (bad[l] <= r ? "NO" : "YES") << '\n';
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
