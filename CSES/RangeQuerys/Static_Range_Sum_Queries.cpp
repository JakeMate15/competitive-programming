#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)   for(long long (i)=0; i<n; i++)
typedef long long ll;


int main(){
    int n,q;    cin>>n>>q;
    vector<int> a (n);
    forn(i,n)   cin>>a[i];

    int len = (int) sqrt (n + .0) + 1; 
    vector<int> b (len);
    for (int i=0; i<n; ++i)
        b[i / len] += a[i];

    forn(i,q) {
        int l, r;
        cin>>l>>r;
        l--;
        int sum = 0;
        int c_l = l / len,   c_r = r / len;
        if (c_l == c_r)
            for (int i=l; i<=r; ++i)
                sum += a[i];
        else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                sum += a[i];
            for (int i=c_l+1; i<=c_r-1; ++i)
                sum += b[i];
            for (int i=c_r*len; i<=r; ++i)
                sum += a[i];
        }
        cout << sum << "\n";
    }

    return 0;
}