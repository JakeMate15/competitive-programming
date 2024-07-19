#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(v)          v.begin(), v.end()
#define sz(a)           (int)a.size()

void sol() {
    int n;
    string s;
    cin >> n >> s;

    int j = 0;
    for(int i = 1; i < n && s[i] <= s[i - 1]; ++i){
        j++;
    }

    if(s[0] == s[1])
        j = 0;
    for(int i = 0; i <= j; ++i)
        cout << s[i];
    for(int i = j; i >= 0; --i)
        cout << s[i];

    cout << "\n";
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