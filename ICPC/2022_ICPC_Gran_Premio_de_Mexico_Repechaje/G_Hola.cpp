#include <iostream>

using namespace std;

// Variables globales para rastrear el estado de las reflexiones.
bool flipH = false, flipV = false, swapXY = false;

// Calcula la posición real del pixel basado en los estados de reflexión.
void getRealPosition(long long &x, long long &y, long long n) {
    if (swapXY) swap(x, y);
    if (flipH) x = n - x + 1;
    if (flipV) y = n - y + 1;
}

int main() {
    long long n, q;
    cin >> n >> q;

    char queryType;
    for (long long i = 0; i < q; i++) {
        cin >> queryType;
        if (queryType == 'r') {
            char axis;
            cin >> axis;
            if (axis == 'a') flipH = !flipH;
            else if (axis == 'b') flipV = !flipV;
            else if (axis == 'c' || axis == 'd') {
                // Para las reflexiones diagonales, intercambiamos flipH y flipV.
                swap(flipH, flipV);
                // Además, activamos o desactivamos el intercambio de x e y basado en la reflexión diagonal.
                if (axis == 'c') swapXY = !swapXY; // Para la diagonal de esquina inferior izquierda a superior derecha.
                if (axis == 'd') {
                    swapXY = !swapXY; // Para la diagonal de esquina superior izquierda a inferior derecha.
                    flipH = !flipH; // Además, invertimos horizontalmente.
                    flipV = !flipV; // Y invertimos verticalmente.
                }
            }
        } else if (queryType == 'q') {
            long long x, y;
            cin >> x >> y;
            getRealPosition(x, y, n);
            // La fórmula para calcular el ID del pixel después de las reflexiones.
            cout << (x - 1) * n + y << endl;
        }
    }
    return 0;
}
