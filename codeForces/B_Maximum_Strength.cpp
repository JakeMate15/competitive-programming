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
#define sz(a)       (int)a.size()

void sol(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int len1 = sz(s1);
    int len2 = sz(s2);
    
    if (len1 > len2) {
        s2 = string(len1 - len2, '0') + s2;
    } else if (len1 < len2) {
        s1 = string(len2 - len1, '0') + s1;
    }

    lli res = 0;
    forn(i,sz(s1)){
        int c1,c2;
        c1 = s1[i]-'0';
        c2 = s2[i]-'0';

        if(abs(c1-c2)== 0){
            continue;
        }

        if( abs(c1-c2) >=1 ){
            res+=abs(c1-c2);
            i++;
            for(i; i<sz(s1); i++){
                res+=9;
            }
        }
    }

    debug(res);
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}