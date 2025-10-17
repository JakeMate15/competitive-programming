#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

long long calculateTotalRegion(vector<int>& heights) {
    long long ans = 0;
    int n = heights.size();
    
    stack<int> st;
    vector<int> nextGreater(n, n), prevGreater(n, -1);

    auto getIndex = [&] (int i, vector<int> &v) -> void {
        while (!st.empty() && heights[st.top()] <= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            v[i] = st.top();
        }
        st.push(i);
    };

    for (int i = 0; i < n; i++) {
        getIndex(i, prevGreater);
    }

    st = stack<int>();

    for (int i = n - 1; i >= 0; i--) {
        getIndex(i, nextGreater);
    }

    // debug(nextGreater);
    // debug(prevGreater);

    for (int i = 0; i < n; i++) {
        ans += (nextGreater[i] - prevGreater[i] - 1);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (auto &x: heights) {
        cin >> x;
    }

    cout << calculateTotalRegion(heights) << "\n";

    return 0;
}


/*

1 2 3 4 5
_ _ _ _ _

*/