#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void sol(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    vector<int>pref(n);
 
    forn(i,n){
        cin>>arr[i];
        if(i==0){
            pref[0] = arr[0];
        }
        else{
            pref[i] = pref[i-1] + arr[i];
        }
    }
 
    int l,r,k;
    int izq,centro,der;
    while(q--){
        cin>>l>>r>>k;
        
        if(l==1){
            izq = 0;
        }
        else{
            izq = pref[l-2];
        }
 
        centro = k*(r-l+1);
 
        if(r == n){
            der = 0;
        }
        else{
            der = pref[n-1] - pref[r-1];
        }
 
        int suma = izq + centro + der;
        if(suma&1)
            YES
        else 
            NO
    }
 
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}