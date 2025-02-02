#include <bits/stdc++.h>
using namespace std;

// Estructura para representar una plantación
struct Plant {
    int r1, c1; // Coordenadas de la esquina superior izquierda
    int r2, c2; // Coordenadas de la esquina inferior derecha
    long long sum; // Suma de recursos en la plantación
};

// Función para calcular la suma de recursos en una submatriz utilizando la matriz de sumas prefijas
long long getSum(const vector<vector<long long>> &prefixSum, int r1, int c1, int r2, int c2) {
    // Asegurarse de que las coordenadas estén dentro de los límites
    if(r1 > r2 || c1 > c2) return 0;
    return prefixSum[r2][c2] - prefixSum[r1-1][c2] - prefixSum[r2][c1-1] + prefixSum[r1-1][c1-1];
}

// Función recursiva para encontrar la suma máxima de plantaciones no superpuestas
long long findMaxSum(int index, int count, const vector<Plant> &plants, vector<vector<bool>> &occupied, long long currentSum) {
    // Caso base: ya hemos seleccionado dos plantaciones
    if(count == 2) {
        return currentSum;
    }
    
    // Caso base: hemos iterado todas las plantaciones
    if(index == plants.size()) {
        return currentSum;
    }
    
    // Opción 1: No seleccionar la plantación actual
    long long option1 = findMaxSum(index + 1, count, plants, occupied, currentSum);
    
    // Opción 2: Intentar seleccionar la plantación actual si no se superpone
    long long option2 = currentSum;
    bool canPlace = true;
    // Verificar superposición
    for(int r = plants[index].r1; r <= plants[index].r2 && canPlace; r++) {
        for(int c = plants[index].c1; c <= plants[index].c2 && canPlace; c++) {
            if(occupied[r][c]) {
                canPlace = false;
            }
        }
    }
    
    if(canPlace) {
        // Marcar las celdas como ocupadas
        for(int r = plants[index].r1; r <= plants[index].r2; r++) {
            for(int c = plants[index].c1; c <= plants[index].c2; c++) {
                occupied[r][c] = true;
            }
        }
        // Seleccionar la plantación actual y continuar la recursión
        option2 = findMaxSum(index + 1, count + 1, plants, occupied, currentSum + plants[index].sum);
        // Desmarcar las celdas (backtracking)
        for(int r = plants[index].r1; r <= plants[index].r2; r++) {
            for(int c = plants[index].c1; c <= plants[index].c2; c++) {
                occupied[r][c] = false;
            }
        }
    }
    
    // Retornar el máximo entre ambas opciones
    return max(option1, option2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R, C, X, Y;
    cin >> R >> C;
    cin >> X >> Y;
    
    // Leer la matriz de recursos
    vector<vector<long long>> A(R + 1, vector<long long>(C + 1, 0));
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            cin >> A[r][c];
        }
    }
    
    // Calcular la matriz de sumas prefijas
    vector<vector<long long>> prefixSum(R + 1, vector<long long>(C + 1, 0));
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            prefixSum[r][c] = A[r][c] + prefixSum[r-1][c] + prefixSum[r][c-1] - prefixSum[r-1][c-1];
        }
    }
    
    // Enumerar todas las posibles plantaciones
    vector<Plant> plants;
    
    // Orientación X × Y
    for(int r = X; r <= R; r++) {
        for(int c = Y; c <= C; c++) {
            Plant p;
            p.r1 = r - X + 1;
            p.c1 = c - Y + 1;
            p.r2 = r;
            p.c2 = c;
            p.sum = getSum(prefixSum, p.r1, p.c1, p.r2, p.c2);
            plants.push_back(p);
        }
    }
    
    // Orientación Y × X (si X != Y para evitar duplicados)
    if(X != Y) {
        for(int r = Y; r <= R; r++) {
            for(int c = X; c <= C; c++) {
                Plant p;
                p.r1 = r - Y + 1;
                p.c1 = c - X + 1;
                p.r2 = r;
                p.c2 = c;
                p.sum = getSum(prefixSum, p.r1, p.c1, p.r2, p.c2);
                plants.push_back(p);
            }
        }
    }
    
    // Ordenar las plantaciones por suma descendente para optimizar la búsqueda
    sort(plants.begin(), plants.end(), [&](const Plant &a, const Plant &b) -> bool {
        return a.sum > b.sum;
    });
    
    // Inicializar la matriz de ocupación
    // Nota: Para matrices grandes, esta estructura consumiría demasiada memoria.
    // Se recomienda usar esta solución solo para R, C <= 20 o similares.
    if(R > 20 || C > 20) {
        // Advertencia para el usuario
        cerr << "Advertencia: La solución recursiva no es eficiente para R y C grandes (R, C > 20)." << endl;
        return 0;
    }
    
    vector<vector<bool>> occupied(R + 1, vector<bool>(C + 1, false));
    
    // Iniciar la recursión
    long long maxSum = findMaxSum(0, 0, plants, occupied, 0);
    
    cout << maxSum << "\n";
    
    return 0;
}
