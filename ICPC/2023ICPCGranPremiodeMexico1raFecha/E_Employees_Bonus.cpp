//https://codeforces.com/gym/104375/problem/E
#include <bits/stdc++.h>
#define ll long long 
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using  namespace std;
const int N=8e5+5;
const int MAX=2e5+3;
int T[MAX];
int S[MAX];
int F[MAX];
int FT[MAX];
int pare[MAX];
int rk[MAX];
vector<int>t[MAX];
int timer;
void dfs(int node,int par){
    //rk[node]=rk[par]+1;
    S[node]=timer;
    FT[timer]=node;
    timer++;
    for(auto ch:t[node]){
        if(ch==par) continue;
        pare[ch]=node;
        dfs(ch,node);
    }
    F[node]=timer;
    FT[timer]=node;
    timer++;   
}
pair<ll,ll> nums[N];
pair<ll,ll> st[N], arr[N];
ll lazy[N];
void push_up(int i){
    int ch1=2*i+1;
    int ch2=2*i+2;
    st[i]=min(st[ch1],st[ch2]);
}
 
void build(int l, int r, int i){
    lazy[i]=0;
    if(l==r){st[i]=nums[l];return;}
    int m=(l+r)>>1;
    build(l,m,2*i+1);
    build(m+1,r,2*i+2);
    push_up(i);
}
void push_down(int l, int r,int i){
    if(!lazy[i])return;
    int ch1=2*i+1;
    int ch2=2*i+2;
    ll &lzy=lazy[i];
    st[ch1].first+=lzy;
    st[ch2].first+=lzy;
    lazy[ch1]+=lzy;
    lazy[ch2]+=lzy;
    lzy=0;
}
void update(int l, int r, int a, int b,ll x, int i){
    if(a>r||b<l)return;
    if(a<=l&&r<=b){
        st[i].first+=x;
        lazy[i]+=x;
        return;
    }
    push_down(l,r,i);
    int m=(l+r)>>1;
    update(l,m,a,b,x,2*i+1);update(m+1,r,a,b,x,2*i+2);
    push_up(i);
}
pair<ll,ll> query(int l, int r, int a, int b, int i){
    if(a>r||b<l)return {5e17,3e5+1};
    push_down(l,r,i);
    if(a<=l&&r<=b) return st[i];
    int m=(l+r)>>1;
    return min(query(l,m,a,b,2*i+1),query(m+1,r,a,b,2*i+2));
}
int main(){IO

    int n,q;cin>>n>>q;
    int res[n+1];
    ll ai[n+1];
    for(int i=1;i<=n;i++){
        cin>>ai[i];
    }
    for(int i=1;i<=n;i++) res[i]=-1;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    int timer=0;
    dfs(1,-1);
    for(int i=0;i<n*2;i++){
        nums[i]={ai[FT[i]],i};
    }
    build(0,2*n-1,0);
    for(int i=0;i<q;i++){
        ll a,b;cin>>a>>b;
        int s1=S[a],f1=F[a];
        ll sz=(f1-s1+1)/2;
        update(0,2*n-1,s1,f1,-(b/sz),0);
        update(0,2*n-1,s1,s1,-(b%sz),0);
        update(0,2*n-1,f1,f1,-(b%sz),0);
        while(query(0,2*n-1,s1,f1,0).first<=0){
            pair<ll,ll>q1=query(0,2*n-1,s1,f1,0);
            if(res[FT[q1.second]]==-1)res[FT[q1.second]]=i+1;
            update(0,2*n-1,q1.second,q1.second,q1.first+5e17,0);
            q1=query(0,2*n-1,s1,f1,0);
            update(0,2*n-1,q1.second,q1.second,q1.first+5e17,0);
        }    
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<endl;
    }
}