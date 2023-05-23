#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)

void sol(){
    string s;cin>>s;
    lli len = s.size(),maxCeros=-1,aux=0;
    if(len==1){
        s[0]=='1'?  (cout << 1 << "\n"):(cout << 0 << "\n");
        return;
    }

    forn(i,len){
        if(s[i]=='1'){
            if(i==len-1 && s[0]=='1' && aux!=len-1){
                int i=0;
                while(s[i]=='1'){
                    aux++;
                    i++;
                }
            }
            aux++;
        }
        else{
            maxCeros = max(maxCeros,aux);
            aux = 0;
        }
    }
    maxCeros = max(maxCeros,aux);

    //cout << "Los max ceros para " << s << " son: " << maxCeros<<endl;
    lli res = 0;
    if(maxCeros==0)         res = 0;
    else if(maxCeros==1)    res = 1;
    else if(maxCeros==len)  res = len*len;
    else                    res = (maxCeros+1)/2 * ceil( 1.0*(maxCeros+1)/2 );
    //(lli)((maxCeros+1)/2)*ceil(1.0*(maxCeros+1)/2)<< endl;

    cout << res<<"\n";
}

int main(){IO
    int t;cin>>t;
    while(t--)  sol();
}