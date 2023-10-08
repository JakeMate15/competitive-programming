#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n & 1) {
        cout << "4\n";
        cout << "1 " << n - 1 << "\n";
        cout << "1 " << n - 1 << "\n";
        cout << n - 1 << " " << n << "\n";
        cout << n - 1 << " " << n << "\n";
    } 
    else{
        debln(2);
        cout << "1 " << n << '\n';
        cout << "1 " << n << '\n';
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