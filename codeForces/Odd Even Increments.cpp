#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int n;
    vector<int> par;
    vector<int> impar;
 
    cin >> n;
 
    int actual;
 
    for(int i=0; i<n; i++){
        cin >> actual;
 
        if(i%2==0){
            par.push_back(actual%2);
        }
        else{
            impar.push_back(actual%2);
        }
    }
 
    int cant0Par  = count(par.begin(),par.end(),0);
    int cant1Par = count(par.begin(),par.end(),1);
    int cant0impar = count(impar.begin(),impar.end(),0);
    int cant1impar = count(impar.begin(),impar.end(),1);;
 
    /*
    cout << cant0Par << endl;
    cout << cant1Par << endl;
    cout << cant0impar << endl;
    cout << cant1impar << endl;*/
 
 
    if((cant0Par == par.size() || cant1Par== par.size()) && (cant0impar == impar.size() || cant1impar== impar.size()))
        cout << "YES\n";
    else    
        cout << "NO\n";
 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
 
    int t;
 
    cin >> t;
 
    while (t--){
        solve();
    }
    
}