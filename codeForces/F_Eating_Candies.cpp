#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)		v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void sol(){
    int n;
    cin>>n;
    ll a[n];

    forn(i,n)
        cin>>a[i];

    int i=0,j=n-1;
    ll izq=a[i],der=a[j];
    priority_queue<int> pq;
    pq.push(0);

    while(i<j){
        if(izq==der)  pq.push(i+1+n-j);

        if(izq<=der){
            i++;
            izq+=a[i];
        }
        else if(der<izq){
            j--;
            der+=a[j];
        }

    }

    debug(pq.top());
}

int main(){IO
	int t=1;
	cin>>t;
	while(t--)  
		sol();
}