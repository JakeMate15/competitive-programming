#include<bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
ll maxSum(ll a[], int inicio, int fin){
    if(inicio == fin)
        return a[inicio];
    
    int mitad, i;
    ll izq,der,suma,sumaIzq,sumaDer,sumaCentral;
 
    mitad = (inicio+fin)/2;
    izq = maxSum(a,inicio,mitad);
    der = maxSum(a,mitad+1,fin);
 
    suma = 0;
    sumaIzq = a[mitad];
    for(i = mitad; i>=inicio; i--){
            suma+= a[i];
            if(suma > sumaIzq)
                sumaIzq = suma;
    }
 
    suma = 0;
    sumaDer = a[mitad+1];
    for( i = mitad+1; i<=fin; i++){
        suma+=a[i];
        if(suma>sumaDer)
            sumaDer=suma;
    }
 
    sumaCentral = sumaIzq + sumaDer;
 
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