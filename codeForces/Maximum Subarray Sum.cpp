#include<bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
ll maxSum(ll a[], ll inicio, ll fin){
    if(inicio == fin)
        return a[inicio];
    
    
    ll mitad = (inicio+fin)/2;
    ll izq = maxSum(a,inicio,mitad);
    ll der = maxSum(a,mitad+1,fin);
 
    ll suma = 0;
    ll sumaIzq = a[mitad];
    for(ll i = mitad; i>=inicio; i--){
            suma+= a[i];
            if(suma > sumaIzq)
                sumaIzq = suma;
    }
 
    suma = 0;
    ll sumaDer = a[mitad+1];
    for(ll i = mitad+1; i<=fin; i++){
        suma+=a[i];
        if(suma>sumaDer)
            sumaDer=suma;
    }
 
    ll sumaCentral = sumaIzq + sumaDer;
 
    return max(max(sumaCentral,izq),der);
}
 
 
int main(){
    int n;
 
    cin >> n;
    ll numeros[n];
 
    for(int i=0; i<n; i++){
        cin >> numeros[i];
    }
 
    cout << maxSum(numeros, 0, n-1) << "\n";
 
    return 0;
}