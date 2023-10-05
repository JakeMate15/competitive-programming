#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

//Podemos verificar que siempre es mejor comprar un valor mas grande por menos
//Siempre es mejor tomar el valor mas alto posible con la i menor, despues podemos reviasar si sobra dinero
//Podemos construir un arreglo creciente donde a su vez podemos actualizar el valor para cada pos i

void sol(){
    int n, k;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = n - 2; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }

    cin >> k;
    
    int t = k;
    for(int i = 0; i < n; i++) {
        //Cuantas monedas mas me cuesta actualizar hasta aqui
        int add = c[i] - (i == 0 ? 0 : c[i - 1]);
        //Si no cuesta, entonces simplemente puedo actualizar al mismo valor
        //Si cuesta algo, debo de ver si es posible tomar el siguiente 
        t = min(t, add == 0 ? t : k / add);
        k -= add * t;

        deb(t);
    }
    nl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}