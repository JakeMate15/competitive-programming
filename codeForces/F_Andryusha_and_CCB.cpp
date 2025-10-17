#include<bits/stdc++.h>
using namespace std;

#define sz(a)       (int) a.size()
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()

const int MX = 2E5 + 5;
const int MOD = 1E9 + 7;

void sol () {
    int n;
    string t;
    cin >> n >> t;

    vector<int> s(n + 2, 0), a(n + 2, 0), vec;
    for(int i = 0; i <= n + 1; i++)
        s[i] = a[i] = 0;
    for(int i = 2; i <= n; i++){
        a[i] = (t[i - 1] != t[i - 2]);
        if(a[i])
            vec.push_back(i);
    }
    vec.push_back(n + 1);
    int m = sz(vec);
    for(int t = 1; t < m; t++){
        // t elementos por grupo
        int j = -1, c = -1;
        while(1){
            if(j != -1 && j + 1 < m && vec[j] + 1 == vec[j + 1])
                j++;
            else
                c++;
            j += t;
            if(j >= m)
                break;
            s[vec[j]]++;
            s[vec[min(j + c + 1, m - 1)]]--;
        } 
    }
    for(int i = 1; i <= n; i++){
        s[i] += s[i - 1];
        a[i] += a[i - 1];
        cout << s[i] + i - a[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}