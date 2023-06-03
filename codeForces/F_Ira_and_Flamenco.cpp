#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"

const int mod = 1e9+7;

template<typename T>
struct SparseTable{
        vector<vector<T>> ST;
        vector<int> logs;
        int K, N;

        SparseTable(vector<T> & arr){
                N = arr.size();
                K = log2(N) + 2;
                ST.assign(K + 1, vector<T>(N));
                logs.assign(N + 1, 0);
                for(int i = 2; i <= N; ++i)
                        logs[i] = logs[i >> 1] + 1;
                for(int i = 0; i < N; ++i)
                        ST[0][i] = arr[i];
                for(int j = 1; j <= K; ++j)
                        for(int i = 0; i + (1 << j) <= N; ++i)
                                ST[j][i] = 1LL * ST[j - 1][i] * ST[j - 1][i + (1 << (j - 1))]%mod; //put the function accordingly
        }

        T multiplicacion(int l, int r){ //non-idempotent functions
                T ans = 1;
                for(int j = K; j >= 0; --j){
                        if((1 << j) <= r - l + 1){
                                ans = (1LL *ans*ST[j][l])%mod;
                                l += 1 << j;
                        }
                }
                return ans;
        }
};

void sol(){
        int n,m;cin>>n>>m;
        int a[n];
        vector<int> compresion;
        map<int,int> auxCmp;

        forn(i,n){
                cin>>a[i];
                auxCmp[a[i]-1] = auxCmp[a[i]-1];
                auxCmp[a[i]] = auxCmp[a[i]] + 1;
                auxCmp[a[i]+1] = auxCmp[a[i]+1];
        } 

        for(auto [num,rep]: auxCmp){
            compresion.push_back(rep);
        }

        //for(int x: compresion)  cout << x << " ";
        //debug("");

        SparseTable<int> q(compresion);
        int ans = 0;
        forn(i,compresion.size()){
                if(i+m<=compresion.size())
                        (ans+=q.multiplicacion(i,i+m-1))%=mod;
        }
        debug(ans);
}

int main(){IO
        int t=1;
        cin>>t;
        while(t--)  sol();
}

