#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int a,b,c;cin>>a>>b>>c;
    if(a+b==c){
        cout << "+" << endl;
    }
    else{
        cout << "-" << endl;
    }
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}