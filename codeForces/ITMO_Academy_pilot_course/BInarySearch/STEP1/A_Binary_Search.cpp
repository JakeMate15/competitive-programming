//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include<bits/stdc++.h>

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

#define pb push_back

#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))

#define forn(i,n) for(ll i=0;i<n;i++)

const int MX = 300005;

using namespace std;

typedef long long ll;

int main(){
    IO
    int n,t;
    cin >> n >> t;
    int a[n];

    forn(i,n)
        cin >> a[i];
    
    int q;
    while(t--){
        cin >> q;
        int l=0,r=n-1;
        bool res = false;

        while(l<=r){
            int m = (l+r)/2;

            if(a[m]==q){
                res = true;
                break;
            }
            else if(a[m]<q){
                l = m+1;
            }
            else{
                r = m-1;
            }

        }

        if(res)
            YES
        else    
            NO
    }
}