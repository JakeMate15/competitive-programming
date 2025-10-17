#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        char *arr = new char[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int q; cin >> q;
        while(q--){
            int a, b; cin >> a >> b;
            if(a==b){
                cout << 0 << "\n";
                continue;
            }
            int delta = b - a;
            if(arr[a-1] == arr[b-1]){
                if(delta == 1 || (a==1 && b==n))
                    cout << n << "\n";
                else
                    cout << 0 << "\n";
            } else {
                if(n & 1)
                    cout << 2 << "\n";
                else{
                    if(delta & 1)
                        cout << 4 << "\n";
                    else
                        cout << 0 << "\n";
                }
            }
        }
        delete [] arr;
    }
    return 0;
}
