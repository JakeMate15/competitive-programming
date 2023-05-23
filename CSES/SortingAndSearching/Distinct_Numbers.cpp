//https://cses.fi/problemset/task/1621
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;cin>>n;
    set<int>numeros;
    int lec;
    for(int i=0;i<n;i++){
        cin>>lec;
        numeros.insert(lec);
    }
    cout << numeros.size() << endl;;
}