#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)  cin>>a[i];
 
    map<int,int> res;
    int aux;
    for(int i=0; i<n; i++){
        aux = k-a[i];
        if(res.count(aux)){
            cout << res[aux] << " " << i+1 << endl;
            return 0;
        }
        res[a[i]] = i+1;
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}