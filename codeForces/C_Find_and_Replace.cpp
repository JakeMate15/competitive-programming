#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int n;cin>>n;
    string s;cin>>s;

    if(s.size() == 1){
        cout << "YES" << endl;
        return;
    }

    set<int> pares;
    set<int> impares;
    forn(i,n){
        if(i&1){
            if(pares.count(s[i])){
                cout << "NO" << endl;
                return;
            }
            else{
                impares.insert(s[i]);
            }
        }
        else{
            if(impares.count(s[i])){
                cout << "NO" << endl;
                return;
            }
            else{
                pares.insert(s[i]);
            }
        }
    }

    cout << "YES" << endl;
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}