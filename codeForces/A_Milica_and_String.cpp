#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
 
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol(){
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt = count(all(s), 'B');
    if(cnt == k) {
        cout << 0 << "\n";
        return;
    }

    cout << 1 << "\n";
    int i, cuantos ;
    if(cnt < k) {   
        cuantos = k - cnt;

        for(i = 0; i < n; i++) {
            if(cuantos == 0) 
                break;
            cuantos += s[i] == 'A' ? -1 : 0; 
        } 
        
        cout << i << " B\n";
    }
    else {
        cuantos = cnt - k;
        for(i = 0; i < n; i++) {
            if(cuantos == 0)
                break;
            if(s[i] == 'B')
                cuantos--;
        }
        cout << i << " A\n";
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}