#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, m;
    cin >> n >> m;

    vector<string> v1(n), v2(n - 1);
    vector<multiset<char>> s(m);

    for (int i = 0; i < n; i++){
        cin >> v1[i];
        for(int j = 0; j < m; j++)
            s[j].insert(v1[i][j]);
    }
    for(int i = 0; i < n - 1; i++){
        cin >> v2[i];
        for(int j = 0; j < m; j++)
            s[j].erase(s[j].find(v2[i][j]));
    }
    string ans = "";
    for(int i = 0; i < m; i++)
        ans.push_back(*(s[i].begin()));
    cout << ans << endl;
    cout.flush(); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}