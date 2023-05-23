#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    vector<int> sumas(3,0);
    int n,res;
 
    cin >> n;
    while (n--){
        for (int i = 0; i < 3; i++){
            cin >> res;
            sumas[i]+=res;
        }
        
    }
 
    if(sumas[0] == 0 && sumas[1]==0 && sumas[2]==0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
 
    return 0;
}