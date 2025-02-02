#include <iostream>
#include <vector>
#include <cstdlib>    // Para system("clear") y rand()
#include <unistd.h>   // Para usleep()
#include <termios.h>  // Para manejar el teclado sin buffer
#include <fcntl.h>    // Para cambiar las propiedades de la terminal
#include <ctime>
#include <algorithm>

using namespace std;

// Constantes para los elementos del juego
const char WALL = '#';
const char EMPTY = ' ';
const char PACMAN = 'P';
const char GHOST = 'G';
const char POWER_UP = 'O';
const char DOT = '.'; // Puntos normales

// Variables globales
int lives = 3;
int score = 0;
int level = 0;

// Estructura para los fantasmas
struct Ghost {
    int x, y;
};

// Lista de fantasmas iniciales
vector<Ghost> ghosts = { {2, 8}, {7, 2}, {5, 5} };

// Laberintos con tres niveles, incluyendo puntos (.) y power-ups (O)
vector<vector<vector<char>>> levels = {
    // Nivel 1
    {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', 'P', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    },
    // Nivel 2
    {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', 'G', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', 'P', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    },
    // Nivel 3
    {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', 'O', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', 'P', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    }
};

// Posiciones iniciales de Pac-Man
int pacmanX = 8, pacmanY = 8;

// Variables para Power-Up
bool powerUpActive = false;
int powerUpTimer = 0;

// Función para pausar el juego esperando una tecla
void pauseGame() {
    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
}

// Función para limpiar la pantalla
void clearScreen() {
    system("clear"); // Limpia la pantalla en Ubuntu
}

// Función para imprimir el laberinto y la información del juego
void printMaze() {
    clearScreen(); // Limpiar pantalla

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << levels[level][i][j];
        }
        cout << endl;
    }
    cout << "Vidas: " << lives << "    Puntuación: " << score << endl;
    if (powerUpActive) {
        cout << "Power-Up activo! Tiempo restante: " << powerUpTimer << endl;
    }
}

// Función para configurar el terminal para entrada no bloqueante
void setNonBlocking(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // Obtener atributos actuales
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Desactivar modo canónico y eco
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplicar cambios
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // Establecer entrada no bloqueante
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaurar atributos antiguos
        fcntl(STDIN_FILENO, F_SETFL, 0); // Restaurar modo de entrada
    }
}

// Función para verificar si se ha presionado una tecla
bool kbhitCustom() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); // Obtener atributos actuales
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Desactivar modo canónico y eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplicar cambios
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Establecer entrada no bloqueante

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaurar atributos antiguos
    fcntl(STDIN_FILENO, F_SETFL, oldf); // Restaurar modo de entrada

    if (ch != EOF) {
        ungetc(ch, stdin); // Devolver el carácter a la entrada
        return true;
    }

    return false;
}

// Función para mover a Pac-Man según la dirección
void movePacman(char direction) {
    int newX = pacmanX, newY = pacmanY;
    if (direction == 'w') newX--;         // Arriba
    if (direction == 's') newX++;         // Abajo
    if (direction == 'a') newY--;         // Izquierda
    if (direction == 'd') newY++;         // Derecha

    // Verificar límites del laberinto
    if (newX < 0 || newX >= 10 || newY < 0 || newY >= 10)
        return;

    // Verificar si la siguiente posición es transitable
    char nextCell = levels[level][newX][newY];
    if (nextCell == EMPTY || nextCell == DOT || nextCell == POWER_UP) {
        if (nextCell == DOT) {
            score += 10; // Puntuación por recoger un punto
        }
        if (nextCell == POWER_UP) {
            powerUpActive = true;
            powerUpTimer = 50; // Duración del power-up en ciclos
            score += 50;        // Puntuación por recoger power-up
        }

        // Actualizar posiciones en el laberinto
        levels[level][pacmanX][pacmanY] = EMPTY;
        pacmanX = newX;
        pacmanY = newY;
        levels[level][pacmanX][pacmanY] = PACMAN;

        // Incrementar puntuación por movimiento
        score += 10;
    }
}

// Función para mover a los fantasmas con IA básica hacia Pac-Man
void moveGhosts() {
    for (auto &ghost : ghosts) {
        if (ghost.x == -1 && ghost.y == -1) continue; // Fantasma eliminado

        // Determinar dirección hacia Pac-Man
        int dx = pacmanX - ghost.x;
        int dy = pacmanY - ghost.y;
        int newX = ghost.x;
        int newY = ghost.y;

        if (abs(dx) > abs(dy)) {
            newX += (dx > 0) ? 1 : -1;
        } else {
            newY += (dy > 0) ? 1 : -1;
        }

        // Verificar límites del laberinto
        if (newX < 0 || newX >= 10 || newY < 0 || newY >= 10)
            continue;

        char targetCell = levels[level][newX][newY];
        if (targetCell == EMPTY || targetCell == PACMAN || targetCell == DOT || targetCell == POWER_UP) {
            // Si el fantasma se mueve a donde está Pac-Man, manejar colisión
            if (targetCell == PACMAN || targetCell == DOT || targetCell == POWER_UP) {
                if (powerUpActive) {
                    // Eliminar el fantasma y aumentar puntuación
                    score += 100;
                    levels[level][ghost.x][ghost.y] = EMPTY;
                    ghost.x = -1;
                    ghost.y = -1;
                } else {
                    lives--;
                    cout << "\n¡Te atrapó el fantasma! Vidas restantes: " << lives << endl;
                    if (lives <= 0) {
                        cout << "¡Has perdido todas tus vidas! Fin del juego." << endl;
                        exit(0);
                    }
                    pauseGame();
                }
            }

            // Actualizar posición del fantasma
            levels[level][ghost.x][ghost.y] = EMPTY;
            ghost.x = newX;
            ghost.y = newY;
            levels[level][ghost.x][ghost.y] = GHOST;
        }
    }
}

// Función para verificar colisiones entre Pac-Man y los fantasmas
void checkCollision() {
    for (auto &ghost : ghosts) {
        if (ghost.x == -1 && ghost.y == -1) continue; // Fantasma eliminado

        if (pacmanX == ghost.x && pacmanY == ghost.y) {
            if (powerUpActive) {
                // Eliminar el fantasma y aumentar la puntuación
                score += 100;
                ghost.x = -1; // Fuera del laberinto
                ghost.y = -1;
                cout << "\n¡Fantasma comido! Puntuación: " << score << endl;
            } else {
                lives--;
                cout << "\n¡Te atrapó el fantasma! Vidas restantes: " << lives << endl;
                if (lives <= 0) {
                    cout << "¡Has perdido todas tus vidas! Fin del juego." << endl;
                    exit(0);
                }
                pauseGame();
            }
        }
    }
}

// Función para actualizar el estado del Power-Up
void updatePowerUp() {
    if (powerUpActive) {
        powerUpTimer--;
        if (powerUpTimer <= 0) {
            powerUpActive = false;
            cout << "\nPower-Up terminado. Los fantasmas ya no son vulnerables." << endl;
        }
    }
}

// Función para verificar si el nivel ha sido completado
void checkLevelCompletion() {
    // Verificar si todos los puntos y power-ups han sido recogidos para pasar de nivel
    bool levelComplete = true;
    for (int i = 0; i < 10 && levelComplete; i++) {
        for (int j = 0; j < 10 && levelComplete; j++) {
            if (levels[level][i][j] == DOT || levels[level][i][j] == POWER_UP) {
                levelComplete = false;
            }
        }
    }

    if (levelComplete) {
        cout << "\n¡Felicidades! Has completado el nivel " << level + 1 << endl;
        score += 500; // Bonus por completar el nivel
        level++;
        if (level >= levels.size()) {
            cout << "¡Has ganado el juego! Puntuación final: " << score << endl;
            exit(0);
        }
        // Reiniciar posiciones
        pacmanX = 8;
        pacmanY = 8;
        levels[level][pacmanX][pacmanY] = PACMAN;

        // Reiniciar fantasmas
        for (auto &ghost : ghosts) {
            ghost.x = 2;
            ghost.y = 8;
            levels[level][ghost.x][ghost.y] = GHOST;
        }
        pauseGame();
    }
}

int main() {
    // Inicializar la semilla para números aleatorios
    srand(time(0));

    // Configurar el terminal para entrada no bloqueante
    setNonBlocking(true);

    while (true) {
        printMaze();

        // Manejar entrada del usuario
        if (kbhitCustom()) {
            char input = getchar();
            input = tolower(input);
            if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
                movePacman(input);
            }
            if (input == 'q') { // Opción para salir del juego
                break;
            }
        }

        moveGhosts();
        checkCollision();
        updatePowerUp();
        checkLevelCompletion();

        usleep(100000);  // Pausa para no sobrecargar la CPU
    }

    // Restaurar el terminal antes de salir
    setNonBlocking(false);
    return 0;
}
