#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int main(){
    ll n, suma =0, entrada;
 
    cin >> n;
 
    for(int i=0; i<n-1; i++){
        cin >> entrada;
        suma+=entrada;
    }
 
    cout << ((n*(n+1))/2) - suma << endl;
}