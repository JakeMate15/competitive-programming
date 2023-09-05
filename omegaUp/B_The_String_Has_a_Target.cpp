#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void sol(){
    int n;
    string s;

    cin>>n>>s;
    auto it = min_element(all(s));
    char mn = *it;
    int ult = it-s.begin();

    forr(i,ult,n){
        if(s[i] == mn)  ult = i;
    }

    cout << s[ult];
    forn(i,n){
        if(i==ult)  continue;
        cout << s[i];
    }

    debln("");
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}