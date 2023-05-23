//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
#include<bits/stdc++.h>

using namespace std;

int lb(int *a,int x, int n){
    int l = -1, r = n;
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] > x) r = m;
        else l = m;
    }
    return l;
}

int up(int *a,int x,int n){
    int l = -1, r = n;
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] < x) l = m;
        else r = m;
    }
    return r;
}


int main(){
    int n,k;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cin>>k;
    sort(a,a+n);
    
    while(k--){
        int l,r;
        cin >> l >> r;
        //cout << lb(a,l,n) << "\n";
        //cout << "estoy buscando r " << r << "\n";
        //cout << up(a,r,n) << "\n";
        cout << lb(a,r,n)-up(a,l,n)+1 << " ";
    }
}