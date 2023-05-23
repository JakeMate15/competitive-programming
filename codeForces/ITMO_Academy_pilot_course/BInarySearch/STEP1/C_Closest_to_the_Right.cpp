//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    while(k--){
        int l=0,r=n-1,m,x;
        int res = n;
        cin>>x;

        while(l<=r){
            m = l+(r-l)/2;

            if(arr[m]>=x){
                r = m-1;
                res = m;
            }
            else{
                l = m+1;
            }
        }

        
        cout << ++res << "\n";

    }
}