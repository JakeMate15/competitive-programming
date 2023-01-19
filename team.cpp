#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;cin >> n;
    int res = 0,a,b,c;

    for(int i=0; i<n; i++){
        cin >> a >> b >> c;

        if(a+b+c>=2){
            res++;
        }
    }

    cout << res << endl;

    return 0;
}