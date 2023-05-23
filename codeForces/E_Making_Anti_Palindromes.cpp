#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

bool grupos(vector<int>& a) {
    map<int, unordered_set<int>> valorN;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            valorN[a[i]].insert(i);
        }
    }

    unordered_set<int> posAsig;
    for (auto const& [valor, posi] : valorN) {
        bool is_possible = true;
        for (auto const& pos : posi) {
            if (posAsig.count(pos) > 0) {
                is_possible = false;
                break;
            }
        }
        if (is_possible) {
            posAsig.insert(posi.begin(), posi.end());
        } else {
            return false;
        }
    }

    return true;
}

void sol(){
    int n;cin>>n;
    string s;cin>>s;
    if(n&1){
        debug(-1);
        return;
    }

    int iguales = 0;
    vector<int> a(26);

    forn(i,n/2){
        if(s[i] == s[n-i-1]){
            iguales++;
            a[s[i]-'a']++;
        }
    }

    if(iguales==0){
        debug(0);
        return;
    }
    else{
        if(grupos(a)){
            if()
        }
    }
}

int main(){IO
    int t=1;cin>>t;
    while(t--)  sol();
}
