#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()
#define sz(a)   (int)a.size()
typedef long long ll;

const int mod = 1E9 + 7;
const int MX = 1E5 + 5;

// bool ok (int ceros, int unos, int comodines) {
//     if ((comodines % 2 == 0) && ((ceros + comodines / 2) == (unos + comodines / 2)))  return true;

//     cerr << ceros << " " << unos << " " << comodines << "\n";
//     if (ceros > unos) 
//         swap(ceros, unos);

//     cerr << ceros << " " << unos << " " << comodines << "\n";

//     int dif = unos - ceros;
//     cerr << "la dif es " << dif << "\n";

//     if (comodines < dif)
//         return false;

//     comodines -= dif;
//     ceros += dif;

//     cerr << ceros << " " << unos << " " << comodines << "\n";

//     return ((comodines % 2 == 0) && ((ceros + comodines / 2) == (unos + comodines / 2)));
// }

void sol () {
    int n,k;
    cin >> n >> k;
    
    string s, s2;
    cin >> s;
    s2 = s;

    bool f = true;
    for(int i = 0; i < n; i++) {
        if(s[i] != '?') {
            for(int j = i - k; j >= 0 && f; j-=k) {
                if(s[j] != '?' && s[j] != s[i]) f = false;
                else if(s[j] == s[i]) break;
                else s2[j] = s[i];
            }
            for(int j= i + k; j < n && f; j += k) {
                if(s[j] != '?' && s[j] != s[i]) f = false;
                else if(s[j] == s[i]) break;
                else s2[j] = s[i];
            }
        }
        if(!f) break;
    }

    if(f) {
        int x, y, z;
        x = y = z = 0;
        int l = 0;
        int r = 0;
        while(r < n) {
            if(r - l < k) {
                if(s2[r] == '1') x++;
                else if(s2[r] == '0') y++;
                else z++;
                r++;
            }
            else {
                if(max(x, y) - min(x, y) > z) {
                    f = false;
                    break;
                }
                else {
                    if(s2[l] == '1') x--;
                    else if(s2[l] == '0') y--;
                    else z--;
                    l++;
                }
            }
        }
        if(max(x,y) - min(x,y) > z && f) f = false;
    }

    cout << (f ? "YES" : "NO") << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; 
    cin >> t;

    while (t--) {
        sol();
    }

    return 0;
}

/*
    Entrada de datos: La función primero lee dos enteros, n y k, donde n es la longitud de la cadena de bits y k es el tamaño del substring que debe ser equilibrado (es decir, debe tener igual número de 0s y 1s). Luego, lee la cadena s que contiene 0s, 1s y posiblemente caracteres '?', que representan bits desconocidos.

    Inicialización y procesamiento de la cadena:
        Se hace una copia de la cadena s en s2.
        
        Se itera sobre cada carácter de s. Si el carácter no es un '?', se intenta propagar su valor a los caracteres que están a 
        distancias múltiplos de k tanto hacia atrás como hacia adelante, siempre que estos caracteres sean '?' (indicando que 
        pueden tomar cualquier valor) o sean iguales al carácter actual. Si se encuentra un conflicto (un carácter no '?' 
        diferente al carácter actual a una distancia múltiplo de k), se marca el proceso como fallido (f = false) y se termina el 
        bucle.

    Verificación de la condición de equilibrio:
        Si después del paso anterior no se encontró ningún conflicto, se procede a verificar si es posible ajustar los '?' restantes de manera que cada substring de tamaño k tenga igual número de 0s y 1s.
        Se utilizan cuatro contadores: x para contar los '1', y para los '0', z para los '?', y un par de índices l y r para manejar una ventana deslizante de tamaño k sobre s2.
        La idea es mantener la ventana deslizante de modo que contenga exactamente k caracteres y verificar si la cantidad máxima de 0s o 1s en la ventana, menos la cantidad mínima de estos, es mayor a la cantidad de '?'. Si esto sucede, significa que no es posible asignar valores a los '?' de manera que se cumpla la condición de equilibrio. Si se logra pasar esta verificación para todas las ventanas posibles, la cadena puede considerarse como potencialmente k-balanced.

    Salida:
        Finalmente, si después de todas las verificaciones la bandera f sigue siendo verdadera, se imprime "YES", indicando que es posible convertir la cadena s en una cadena k-balanced reemplazando adecuadamente los '?'. Si f es falsa en algún punto, se imprime "NO".


*/
