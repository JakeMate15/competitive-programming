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

vector<int>num;
int dp[20][20][2];

int mem(int pos, int cant, int goodAll){
    if(cant>3)  return 0;
    if(pos==num.size()){
        if(cant<=3) return 1;
        return 0;
    }

    int &a = dp[pos][cant][goodAll];
    if(a!=-1)   return a;
    a = 0;

    int limite = goodAll==0?num[pos]:9;
    fore(dig,0,limite){
        int nG = goodAll;
        int nCant = cant;
        if(goodAll==0 && dig<limite)    nG=1;
        if(dig!=0)  nCant++;
        if(nCant<=3)    a+=mem(pos+1,nCant,nG);
    } 

    return a;
}

int solve(lli b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    lli res = mem(0, 0, 0);
    return res;
}

int main(){IO
    int t;cin>>t;
    lli a,b;
    while(t--){
        cin >> a >> b;
        int res = solve(b) - solve(a-1);
        debug(res);
    }
}