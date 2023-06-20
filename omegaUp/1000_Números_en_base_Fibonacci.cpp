#include <stdio.h>

typedef long long int lli;


int main(){
    lli n;
    scanf("%lld", &n);
    lli fib[46];
    fib[0] = fib[1] = 1;

    for(int i=2; i<=44; i++)
        fib[i] = fib[i-1] + fib[i-2];

    int res[46], idx = 0;
    int fin = 0;

    for(int i=2; i<=44; i++){
        if(fib[i] <= n){
            fin = i;
        }
    }

    while(fin >= 0){
        if(fib[fin] <= n){
            n -= fib[fin];
            res[idx++] = fin;
        }
        else if(n == 0)
            break;
        fin--;
    }

    printf("%d\n", idx);
    for(int i=0; i<idx; i++)
        printf("%d ", res[i]);
    printf("\n");
    
    return 0;
}
