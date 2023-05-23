#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)   for(long long (i)=0; i<n; i++)
#define IO  ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

int main(){IO
    string s;cin>>s;
    int i=0,j=s.size()-1,cambios=0;

    while(i<j && cambios<2){
        if(s[i]!=s[j])  cambios++;

        i++;
        j--;
    }

    if ( cambios == 1 )
		cout << "YES";
	else if ( s.size() % 2 && cambios == 0 )
		cout << "YES";
	else
		cout << "NO";
}