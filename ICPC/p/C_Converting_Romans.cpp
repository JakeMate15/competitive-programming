#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;

    map<char, int> val = {{'I',1}, {'V',5},{'X',10},{'L', 50}, {'C', 100}, {'D',500},{'M',1000}};
    while(tt--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<pair<int,int>> pos;
        for(int i=0; i<s.length(); i++) {
            pos.push_back({val[s[i]],i});
        }
        sort(pos.rbegin(), pos.rend());
        vector<bool> used(n);
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int val1,j;
            tie(val1,j) = pos[i];
            if(used[j]) continue;
            ans += val1;
            used[j] = 1;
            j--;
            while(j >= 0) {
                char c = s[j];
                int val2 = val[c];
                if(val2 >= val1) break;
                used[j] = 1;
                j--;
                ans -= val2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}