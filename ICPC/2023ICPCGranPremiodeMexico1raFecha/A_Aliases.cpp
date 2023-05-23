//https://codeforces.com/gym/104375/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;cin>>q;
    map<string,int> nombres;

    while(q--){
        int n;string x;
        cin>>n;
        string aux="";
        while(n--){
            cin>>x;
            aux+=x[0];
        }
        if(nombres.count(aux))  nombres[aux]++;
        else                    nombres[aux]=1;
    }
    
    int res = 0;
    for(auto x: nombres){
        if(x.second==1) res++;
    }
    cout << res << "\n";
    return 0;
}