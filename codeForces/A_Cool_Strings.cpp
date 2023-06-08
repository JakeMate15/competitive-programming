#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

bool compare(const pair<pair<int, int>, char>& a, const pair<pair<int, int>, char>& b) {
    if (a.first.first > b.first.first) {
        return true;
    }
    else if (a.first.first < b.first.first) {
        return false;
    }
    else {
        return a.first.second < b.first.second;
    }
}

void sol(){
    string s;
    cin>>s;
    unordered_map<char, pair<int, int>> frecuenciaUltimoIndice;

    for (int i = 0; i < s.size(); i++) {
        char letra = s[i];
        frecuenciaUltimoIndice[letra].first++; 
        frecuenciaUltimoIndice[letra].second = i; 
    }

    vector< pair<pair<int,int>, char> > res;
    for(auto [letra,inf]: frecuenciaUltimoIndice){
        res.push_back({{inf.first,inf.second},letra});
        //cout << letra << ": " << inf.first << " " << inf.second << "\n"; 
    }

    sort(all(res),compare);

    int flag = res[0].first.first;
    for(auto [inf,letra]: res){
        if(inf.first < flag){
            break;;
        }
        cout << letra;
    }
    debug("");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}