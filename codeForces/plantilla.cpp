#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    std::vector<std::vector<int>> matriz = {
        {15, 20, 110},
        {90, 90, 100},
        {40, 40, 40}
    };

    // Ordenar la matriz usando std::sort
    std::sort(matriz.begin(), matriz.end());

    cout << ({15, 20, 110} > {40, 40, 40}) << endl;

    // Imprimir la matriz ordenada
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
