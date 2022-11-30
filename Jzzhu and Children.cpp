#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int i, n, m, ultimo;
    double t, max(0);
    cin >> n >> m;
 
    for (i = 1; i <= n; i++){
        cin >> t;
        if (ceil(t / m) >= max)
        {
            ultimo = i;
            max = ceil(t / m);
        }
    }
 
    cout << ultimo << endl;
    return 0;
}