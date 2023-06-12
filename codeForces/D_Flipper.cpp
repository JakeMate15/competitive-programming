#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define eb(a)       emplace_back(a)

void sol(){
    int n;cin>>n;
    vector<int> ans;
    int a[n];
    forn(i,n)   cin>>a[i];

    int posMax;
    if(a[0] == n)   posMax = max_element(a+1,a+n)-a;
    else            posMax = max_element(a,a+n)-a;

    forr(i,posMax,n)    cout << a[i] << " ";

    int cantidad = n-posMax,fin=0;
    if(cantidad>1 ){
        cout << a[--posMax] << " ";
        //fin = -1;
    }

    posMax--;

    for(int i=posMax; i>=0; i--){
        if(a[i] > a[0]){
            cout << a[i] << " ";
        }
        else{
            fin+=posMax;
            fore(j,0,i){
                cout << a[j] << " ";
            }
            break;
        }
    }

    debug("");
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}


/*
5 4 
9 
3 2 1 
1 
6 
7 6 4 
9 3 8 4 7 
3
*/


/*

5 4 

3 2 1 


7 6 4 
9 3 8 4 7
*/