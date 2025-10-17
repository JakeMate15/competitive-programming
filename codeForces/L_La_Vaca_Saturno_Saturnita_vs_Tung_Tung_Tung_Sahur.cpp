#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MODM = MOD - 1;
int mod_pow(long long a,long long e){
    long long r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return int(r);
}
int mod_string(const string& s,int m){
    long long res=0;
    for(char c:s) res=(res*10+(c-'0'))%m;
    return int(res);
}
string div_string(string s,int d,int& rem){
    string q; rem=0; bool nz=false;
    for(char c:s){
        rem=rem*10+(c-'0');
        int v=rem/d;
        rem-=v*d;
        if(v||nz){ q.push_back(char('0'+v)); nz=true; }
    }
    if(!nz) q="0";
    return q;
}
vector<int> toBase(string s,int b){
    if(s=="0") return {0};
    vector<int> rev;
    while(s!="0"){
        int r;
        s=div_string(s,b,r);
        rev.push_back(r);
    }
    reverse(rev.begin(),rev.end());
    return rev;
}
void markEdge(int k,const vector<int>& low,const vector<int>& high,int b,bitset<33000>& reach){
    const int MAXG=32967;
    static bitset<33000> dp[2][2],ndp[2][2];
    for(int tl=0;tl<2;tl++)for(int th=0;th<2;th++)dp[tl][th].reset();
    dp[1][1].set(0);
    for(int pos=0;pos<k;pos++){
        for(int tl=0;tl<2;tl++)for(int th=0;th<2;th++)ndp[tl][th].reset();
        for(int tl=0;tl<2;tl++)for(int th=0;th<2;th++){
            auto cur=dp[tl][th];
            if(cur.none()) continue;
            int lo=tl?low[pos]:0;
            int hi=th?high[pos]:b-1;
            if(pos==0&&k>1) lo=max(lo,1);
            for(int d=lo;d<=hi;d++){
                int ntl=tl&&(d==low[pos]);
                int nth=th&&(d==high[pos]);
                ndp[ntl][nth]|=(cur<<d);
            }
        }
        for(int tl=0;tl<2;tl++)for(int th=0;th<2;th++)dp[tl][th]=ndp[tl][th];
    }
    for(int tl=0;tl<2;tl++)for(int th=0;th<2;th++){
        auto cur=dp[tl][th];
        for(int s=cur._Find_first();s<33000;s=cur._Find_next(s)){
            int g=k*(b-1)-s;
            if(g>=0&&g<=MAXG) reach.set(g);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b; string l,r;
    if(!(cin>>b>>l>>r)) return 0;
    vector<int> Ldigits=toBase(l,b),Rdigits=toBase(r,b);
    int kL=Ldigits.size(),kR=Rdigits.size();
    const int MAXG=32967;
    bitset<33000> reach;
    for(int k=kL+1;k<=kR-1;k++){
        int mx=k*(b-1)-1;
        for(int g=0;g<=mx;g++) reach.set(g);
    }
    markEdge(kL,Ldigits,(kL==kR)?Rdigits:vector<int>(Ldigits.size(),b-1),b,reach);
    if(kR!=kL) markEdge(kR,vector<int>(Rdigits.size(),0),Rdigits,b,reach);
    int basis[16]={0};
    int rank=0;
    for(int g=reach._Find_first();g<33000;g=reach._Find_next(g)){
        int v=g;
        for(int bit=15;bit>=0;bit--){
            if(!(v>>bit&1)) continue;
            if(!basis[bit]){ basis[bit]=v; rank++; break; }
            v^=basis[bit];
        }
    }
    int rmod=mod_string(r,MODM);
    int lmod=mod_string(l,MODM);
    int Nmod=(rmod-lmod)%MODM;
    if(Nmod<0) Nmod+=MODM;
    Nmod=(Nmod+1)%MODM;
    int e=(Nmod-rank)%MODM;
    if(e<0) e+=MODM;
    cout<<mod_pow(2,e)<<"\n";
    return 0;
}
