#include<bits/stdc++.h>

using namespace std;

using my_clock = chrono::steady_clock;

struct Random {
    mt19937_64 engine;
    Random() : engine(my_clock::now().time_since_epoch().count()) {}
    template<class Int> Int integer(Int n) { return integer<Int>(0, n); } // `[0,n)`
    template<class Int> Int integer(Int l, Int r) { return uniform_int_distribution<Int>{l, r-1}(engine); } // `[l,r)`
    double real() { return uniform_real_distribution<double>{0.0, 1.0}(engine); } // `[0,1)`
} rng;

struct Timer {
    using time = my_clock::time_point;
    time start = my_clock::now();
    double elapsed() { // Segundos desde el inicio.
        time now = my_clock::now();
        return chrono::duration<double>(now - start).count();
    }
} timer;

typedef pair<int, int> Point;
typedef tuple<int, int, int> Triumvirate;

// Función para calcular la distancia al cuadrado entre dos puntos
int squared_distance(const Point& p1, const Point& p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

// Función para calcular la estabilidad de un triunvirato
int calculate_stability(const Triumvirate& triumvirate, const vector<Point>& points) {
    int i1 = get<0>(triumvirate);
    int i2 = get<1>(triumvirate);
    int i3 = get<2>(triumvirate);

    int d1 = squared_distance(points[i1], points[i2]);
    int d2 = squared_distance(points[i1], points[i3]);
    int d3 = squared_distance(points[i2], points[i3]);

    return max({d1, d2, d3}) - min({d1, d2, d3});
}

// Función para generar una solución inicial aleatoria
vector<Triumvirate> generate_initial_solution(const vector<Point>& points) {
    int n = points.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    shuffle(indices.begin(), indices.end(), rng.engine);
    
    vector<Triumvirate> groups;
    for (int i = 0; i < n; i += 3) {
        groups.emplace_back(indices[i], indices[i+1], indices[i+2]);
    }
    return groups;
}

// Función para calcular la estabilidad total de una solución
int calculate_total_stability(const vector<Triumvirate>& groups, const vector<Point>& points) {
    int total_stability = 0;
    for (const auto& group : groups) {
        total_stability += calculate_stability(group, points);
    }
    return total_stability;
}

// Función para intercambiar puntos entre dos grupos aleatoriamente
void random_swap(vector<Triumvirate>& groups) {
    int i = rng.integer(0, groups.size());
    int j = rng.integer(0, groups.size());
    if (i != j) {
        int a = rng.integer(0, 3);
        int b = rng.integer(0, 3);
        int temp = get<a>(groups[i]);
        get<a>(groups[i]) = get<b>(groups[j]);
        get<b>(groups[j]) = temp;
    }
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // Generar una solución inicial aleatoria
    auto initial_groups = generate_initial_solution(points);
    auto current_solution = initial_groups;
    int current_energy = calculate_total_stability(current_solution, points);

    // Definir la función de energía y la función de actualización para el recocido simulado
    auto energy_function = [&]() {
        return calculate_total_stability(current_solution, points);
    };

    auto update_function = [&]() {
        random_swap(current_solution);
    };

    // Inicializar y ejecutar el recocido simulado
    Annealing<decltype(energy_function), decltype(update_function)> annealing(energy_function, update_function);
    annealing.simulate(5.0, 1.0); // Simula por 5 segundos

    // Imprimir la mejor solución encontrada
    for (const auto& group : current_solution) {
        cout << get<0>(group) << " " << get<1>(group) << " " << get<2>(group) << "\n";
    }

    return 0;
}
