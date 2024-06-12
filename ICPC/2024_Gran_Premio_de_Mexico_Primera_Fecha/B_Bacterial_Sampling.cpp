#include <iostream>
#include <vector>

const int LIFE_SPAN = 20;
const int MATURATION_TIME = 2;
const int REPRODUCTION_TIME = 4;

long long bacteriaCountAtTime(int N) {
    if (N == 0) return 1; // Inicialmente hay una bacteria
    
    std::vector<long long> B(LIFE_SPAN + 1, 0); // Contador de bacterias por edad
    B[0] = 1; // Una bacteria inicial
    
    for (int t = 1; t <= N; ++t) {
        long long newBorns = B[REPRODUCTION_TIME]; // Bacterias que se reproducen este minuto
        
        // Actualiza las edades de las bacterias
        for (int age = LIFE_SPAN; age > 0; --age) {
            B[age] = B[age - 1];
        }
        
        B[0] = newBorns; // Nuevas bacterias nacen
        B[MATURATION_TIME] += newBorns; // Las nuevas bacterias maduras después de 2 minutos
    }
    
    long long totalBacteria = 0;
    for (int age = 0; age <= LIFE_SPAN; ++age) {
        totalBacteria += B[age];
    }
    
    return totalBacteria;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int N;
        std::cout << "Ingrese el minuto N: ";
        std::cin >> N;
        std::cout << "Número de bacterias en el minuto " << N << " es: " << bacteriaCountAtTime(N) << std::endl;
    }
    return 0;
}
