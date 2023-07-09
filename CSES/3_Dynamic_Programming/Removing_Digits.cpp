//https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;cin>>n;
    int res = 0;
    while(n!=0){
        string aux = to_string(n);
        char maximo='0';
        for(char c:aux){
            maximo = max(maximo,c);
        }
 
        n-=(maximo-'0');
        res++;
    }
 
    cout << res << endl;
}