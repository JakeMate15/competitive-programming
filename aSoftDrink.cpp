#include <bits/stdc++.h>
 
using namespace std;
 
bool mayorMenor(int, int);
 
int main(){
    int n,k,ml,l,r,g,x,y,i;
    vector<int> v1;
    int salsa, limones, litros;
 
    cin >> n >> k >> ml >> l >> r >> g >> x >> y;
 
    salsa = (g/y)/n;
    limones = (l*r)/n;
    litros = ((k*ml)/x)/n;
 
    v1.push_back(salsa);
    v1.push_back(limones);
    v1.push_back(litros);
 
    sort(v1.begin(),v1.end());
 
    cout << v1.at(0) << endl;
 
    return 0;
}