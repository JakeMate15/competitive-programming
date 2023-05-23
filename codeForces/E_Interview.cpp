#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    fore(i,1,n) cin >> a[i];
    int l = 1, r = n - 1;

    while(l <= r){
        int md = (l+r)/2;
        cout << "? " << md << " ";
        int sum = 0;
        for(int i = 1; i <= md; ++i)
            cout << i << " ", sum += a[i];
        cout << endl;
        int x;
        cin >> x;
        if(x > sum)
            r = md - 1;
        else l = md + 1;
    }
    cout << "! " << r + 1 << endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)  sol();
}