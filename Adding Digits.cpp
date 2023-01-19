#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a,b,n;
    cin >> a >> b >> n;

    int f=0;
    for(int i=0; i<10; i++){
        if((a*10+i)%b==0){
            a = a * 10 + i;
            f=1;
            break;
        }
    }

    if(!f){
        cout << -1 << endl;
        return 0;
    }

    n--;

    cout << a;
    for(int i=0; i<n; i++){
        cout << 0;
    }

    cout << endl;
	
	return 0;
}