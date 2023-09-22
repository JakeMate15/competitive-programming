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
    string s;
    cin>>s;
    int n = sz(s);

    int b = count(all(s),'B');
    int res = 0;

    if( (s[0] == 'A' && s[n - 1] == 'B') || (s[0] == 'B' && s[n - 1] == 'A') ) {
        res = n - b;
    }
    else if(b == 0 || b == n) {
        res = 0;
    }
    else{
        int mn = INT_MAX;
        int curr = 0;
        
        forn(i,n) {
            if(s[i] == 'B') {
                mn = min(mn,curr);
                curr = 0;
            }    
            else {
                curr++;
                res++;
            }
        }
        mn = min(mn,curr);

        if(s.find("BB") == string::npos) {
            res-=mn;
        }
    }


    debln(res);
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