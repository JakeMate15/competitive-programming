#include <iostream>
#include <cmath>
 
using namespace std;
 
int main(){
    int i,j,col,fil,num;
 
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin >> num;
 
            if(num==1){
                fil = abs((i+1)-3);
                col = abs((j+1)-3);
            }
        }
    }
 
    cout << (fil+col) << endl;
 
    return 0;
}