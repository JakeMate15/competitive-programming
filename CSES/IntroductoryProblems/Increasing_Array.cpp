//https://cses.fi/problemset/result/5170510/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n;
    cin>>n;
 
    vector<ll>numeros(n);
    for(int i=0;i<n;i++){
        cin>>numeros[i];
    }
    
    
    ll res = 0;
    for(int i=1;i<n;i++){
        if(numeros[i-1]>numeros[i]){
            int sum = numeros[i-1]-numeros[i];
            res+=sum;
            numeros[i]+=sum;
        }
    }
    
    cout << res << endl;
    return 0;
}