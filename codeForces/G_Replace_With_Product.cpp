#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

//Lo importante es delimitar la que la suma es a lo mas 2 * n
//entonces si la multiplicacion es mayor, siempre sera viable tomar desdes 1 a n
//Probar los demas casos

void sol(){
    int n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    int l = 0, r = n - 1;
    while (l < r && a[l] == 1) {
        l++;
    }
    while (l < r && a[r] == 1) {
        r--;
    }

    ll res = 1;
    for (int i = l; i <= r; i++) {
        res *= a[i];
        if (res > 1E9) {
            std::cout << l + 1 << " " << r + 1 << "\n";
            return;
        }
    }
    
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) {
            p.push_back(i);
        }
    }

    ll suma = accumulate(all(a), 0);
    int L = 1, R = 1, ans = suma;

    for (int i = 0; i < p.size(); i++) {
        int l = p[i];
        int res = 1;
        int s = 0;
        for (int j = i; j < p.size(); j++) {
            int r = p[j];
            res *= a[r];
            s += a[r] - 1;
            int v = suma - (r - l + 1) - s + res;
            if (v > ans) {
                ans = v;
                L = l + 1, R = r + 1;
            }
        }
    }

    deb(L);debln(R);

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