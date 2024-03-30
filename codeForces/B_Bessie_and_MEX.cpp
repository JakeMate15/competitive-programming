#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve(int n, vector<int>& a) {
    vector<int> p(n); // Para almacenar la permutación resultante
    set<int> mexSet; // Para almacenar los números disponibles para el MEX

    // Inicialmente, añadimos todos los números de 0 a n - 1 al conjunto MEX
    for (int i = 0; i < n; ++i) {
        mexSet.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        // El valor de p[i] se determina sumando a[i] al MEX actual de p[0] a p[i-1]
        int currentMex = *mexSet.begin(); // El MEX actual es el primer elemento del conjunto
        p[i] = currentMex + a[i];

        // Una vez que p[i] es conocido, se elimina de los candidatos para futuros MEX
        mexSet.erase(p[i]);

        // Si p[i] está en el rango [0, n-1], también necesitamos actualizar mexSet
        if (p[i] < n) {
            mexSet.insert(p[i]);
        }
    }

    // Imprimimos la permutación p construida
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(n, a);
    }
    return 0;
}
