#include <iostream>
using namespace std;

int minHeight(int a, int b, int c) {
    // Si no hay nodos hoja, no es posible formar un árbol.
    if (c < 1) return -1;
    
    // Casos especiales donde el árbol puede ser formado directamente.
    if (a == 0) {
        if (b <= 1) return 1; // Solo un nodo o un nodo con un hijo.
        else return 2; // Más de un nodo con un hijo, requiere al menos dos niveles.
    }
    
    // Calculamos la altura considerando los nodos a, b, c.
    int height = 1; // Inicializamos la altura mínima.
    
    // Calculamos la altura necesaria para acomodar a los nodos con dos hijos.
    while (a > 0 || b > 1) {
        if (a > 0) {
            height++; // Cada nodo con dos hijos aumenta la altura.
            a--;
        } else if (b > 1) {
            height++; // Dos nodos con un hijo pueden ser colocados en niveles sucesivos.
            b -= 2;
        }
    }
    
    return height;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << minHeight(a, b, c) << endl;
    }
    return 0;
}
