#include<bits/stdc++.h>
using namespace std;
 
void hanoi(int n, int a, int c, int b){
    if(n==0)    return;
    hanoi(n-1,a,b,c);
    cout << a << " " << c << endl;
    hanoi(n-1,b,c,a);
}
 
int main(){
    int n;cin>>n;
    int x = 2;
    cout << (x<<(n-1))-1 << endl;
 
    hanoi(n,1,3,2);
 
    return 0;
}