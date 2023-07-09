#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i,n)   for(ll (i)=0; i<n; i++)
#define forr(i,a,n) for(ll i=(a); i<=n; i++)

vector<int> num;
int l,r;
ll dp[20][2];

ll mem(int pos, int longitud,int canUseAll){
    if(len == 1)    return 1;
    if()

    ll &a = dp[pos][canUseAll];
    if(a!=-1) return a;
    a = 0;



    return a;
}

ll f(ll b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    int res = mem(0, 0);
    return res;
}

int main(){
    int n;cin>>n;
    cout << f(n)<< endl;
}
