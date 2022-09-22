#include <bits/stdc++.h>
 
using namespace std;

int main(){
    string s, letras = "hello";
    int i,cmpLetras=0;
 
    cin >> s;
 
    for(i=0;i<s.size();i++){
        if(s[i] == letras[cmpLetras]){
            cmpLetras++;
        }
    }
 
    if(cmpLetras==5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
 
    return 0;
}