#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
typedef long long ll;

void sol(){
    int n;
    cin >> n;

    if((n % 3 == 0 && n <= 9) || (n < 7) ) {
        debln("NO");
        return;
    }

    debln("YES");
    if(n % 3 == 0) {
        cout << "1 4 " << n - 5 << "\n";
    }
    else{
        cout << "1 2 " << n - 3 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}