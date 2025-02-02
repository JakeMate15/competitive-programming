#include <bits/stdc++.h>
using namespace std;

// Función para calcular la longitud de la Subsequencia Común Más Larga (LCS)
int longest_common_subsequence(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    
    // Crear una tabla (m+1) x (n+1) inicializada a 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Construir la tabla dp de abajo hacia arriba
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    // Leer el diario de hechizos
    string spell_diary;
    cin >> spell_diary;
    
    while(t--){
        string s;
        cin >> s;
        
        // Calcular el poder del hechizo (longitud del nombre)
        int poder = s.size();
        
        // Imprimir el nombre del hechizo y su poder
        cout << s << " " << poder << "\n";
        
        // Verificar si el hechizo es genérico (contiene "Restore")
        if(s.find("Restore") != string::npos){
            // Calcular la longitud de la LCS entre el nombre del hechizo y el diario
            int lcs_length = longest_common_subsequence(s, spell_diary);
            cout << lcs_length << "\n";
        }
    }
    
    return 0;
}
