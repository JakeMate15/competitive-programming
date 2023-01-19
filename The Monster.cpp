#include<bits/stdc++.h>

using namespace std;

int gR(int a, int b, int n){
    return b+(n-1)*a;
}

int gM(int c, int d, int n){
    return d+(n-1)*c;
}

int main(){
    int a,b,c,d;
    int n=1;
    int rick,mo; 
    set<int> coincidencias;

    cin >> a >> b >> c >> d;

    if(a>c){

        while(true){
            rick = gR(a,b,n);
            mo = gM(c,d,n);

            if(coincidencias.count(rick)){
                cout << rick << "\n";
                return 0;
            }

            if(coincidencias.count(mo)){
                cout << mo << "\n";
                return 0;
            }

            coincidencias.insert(rick);
            coincidencias.insert(mo);
            n++;
        }

    }
    else if(b==d && a==c){
        cout << gR(a,b,1) << "\n";
    }
    else{
        cout << "-1\n";
    }

    return 0;
}