#include <bits/stdc++.h>
using namespace std;

static const int INF = INT_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    vector<vector<int>> E(n,vector<int>(q+1,0)),S(n,vector<int>(q+1,0));
    vector<int> eventsSnake(q),eventsType(q);
    for(int i=0;i<q;i++){
        char c;int x;cin>>x>>c;--x;
        eventsSnake[i]=x;eventsType[i]=(c=='+');
    }
    for(int i=0;i<q;i++){
        for(int sn=0;sn<n;sn++){
            E[sn][i+1]=E[sn][i];
            S[sn][i+1]=S[sn][i];
        }
        int sn=eventsSnake[i];
        if(eventsType[i]) E[sn][i+1]++; 
        else S[sn][i+1]++;
    }
    vector<int> R(n);
    for(int i=0;i<n;i++) R[i]=E[i][q];
    vector<vector<int>> M(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int mx=INT_MIN;
            for(int k=0;k<=q;k++){
                int val=E[i][k]-S[j][k];
                if(val>mx)mx=val;
            }
            M[i][j]=mx;
        }
    }
    long long leftVal=1,rightVal=n+(long long)q,ans=rightVal;
    while(leftVal<=rightVal){
        long long mid=(leftVal+rightVal)/2;
        vector<vector<long long>> dp(1<<n,vector<long long>(n,1e15));
        for(int i=0;i<n;i++){
            if(1LL<=mid-R[i]) dp[1<<i][i]=1;
        }
        for(int mask=0;mask<(1<<n);mask++){
            for(int last=0;last<n;last++){
                if(((mask>>last)&1)==0) continue;
                long long Llast=dp[mask][last];
                if(Llast>1e14) continue;
                for(int nxt=0;nxt<n;nxt++){
                    if((mask>>nxt)&1) continue;
                    long long Lj=Llast+M[last][nxt]+1;
                    if(Lj<=mid-R[nxt]){
                        int nmask=mask|(1<<nxt);
                        if(Lj<dp[nmask][nxt]) dp[nmask][nxt]=Lj;
                    }
                }
            }
        }
        bool ok=false;
        for(int i=0;i<n;i++){
            if(dp[(1<<n)-1][i]<1e14){ok=true;break;}
        }
        if(ok){ans=mid;rightVal=mid-1;}else leftVal=mid+1;
    }
    cout<<ans<<"\n";
}
