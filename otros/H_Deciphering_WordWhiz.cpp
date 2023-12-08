#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void sol(){
    int n;
    cin >> n;

    string sol;
    cin >> sol;

    map<char, int> a;
    map<string, int> b;
    string nc = "";
    for(auto x: sol) {
        a[x]++;
        nc += '*';
    }
    b[nc]++;

    
    for(int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;

        string curr = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == sol[i]) 
                curr += '*';
            else if(a[s[i]])
                curr += '!';
            else
                curr += 'X';
        }

        b[curr]++;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;
        cout << b[s] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}