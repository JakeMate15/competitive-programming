#include<bits/stdc++.h>
using namespace std;

#define sz(a)   (int) a.size()

typedef long long ll;

int main () {
    int a[2][2];
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
 
    int b = a[0][0] + a[1][0], c = a[0][1] + a[1][1];
    if (b == c) cout << "D";
    else if(b > c)  cout << "A";
    else    cout << "P";
}