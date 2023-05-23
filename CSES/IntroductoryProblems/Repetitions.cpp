#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s;
    int res=1,c=0;
    char l='A';
 
    cin >> s;
 
    for(char d:s){
        if(d==l){
            c++;
            res=max(c,res);
        }
        else{
            l=d;
            c=1;
        }
    }
 
    cout << res << endl;
 
    return 0;
}