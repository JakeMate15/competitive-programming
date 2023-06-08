#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef long double ld;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

void sol(){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;

    if(x1==0 && x2==0 || y1==0 && y2==0){
        cout << setprecision(6) << fixed << distance(x1,y1,x2,y2) << "\n";
        return;
    } 

    x1 = max(x1,x1*-1);
    x2 = max(x2,x2*-1);
    y1 = max(y1,y1*-1);
    y2 = max(y2,y2*-1);

    int r1 = abs(max(x1,y1));
    int r2 = abs(max(x2,y2));
    int radio = min(r1,r2);

    double d1 = abs(r1-r2)*1.0;
    double d2 = (atan(1)*4)*radio/2*1.0;

    //cout << radio << " " << d2 << "\n";
    cout << setprecision(6) << fixed << (d1+d2)*1.0 << "\n";
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}