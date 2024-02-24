#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

void sol() {
	int n, m;
	scanf("%d%d",&n,&m);
	char c=getchar();
	while(!isupper(c)){
		c=getchar();
	}
	vector<vector<int>>a(n),b(n);
	for(int i=0;i<=n-1;++i){
		a[i].resize(m);
		b[i].resize(m);
	}
	for(int i=0;i<=n-1;++i){
		string s;
		cin>>s;
		for(int j=0;j<=m-1;++j){
			switch(s[j]){
				case '.':
					a[i][j]=0;
					break;
				default:
					a[i][j]=s[j]-'A'+1;
					break;
			}
		}
	}
	int cnt=0;
	queue<pair<int,int>>q;
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=m-1;++j){
			if(a[i][j]&&!b[i][j]){
				++cnt;
				q.push({i,j});
				while(!q.empty()){
					auto p=q.front();
					q.pop();
					int x=p.first,y=p.second;
					if(b[x][y]){
						continue;
					}
					b[x][y]=cnt;
					if(x>=1&&!b[x-1][y]&&a[x][y]==a[x-1][y]){
						q.push({x-1,y});
					}
					if(x<=n-2&&!b[x+1][y]&&a[x][y]==a[x+1][y]){
						q.push({x+1,y});
					}
					if(y>=1&&!b[x][y-1]&&a[x][y]==a[x][y-1]){
						q.push({x,y-1});
					}
					if(y<=m-2&&!b[x][y+1]&&a[x][y]==a[x][y+1]){
						q.push({x,y+1});
					}
				}
			}
		}
	}
	set<int>s;
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=m-1;++j){
			if(a[i][j]==c-'A'+1){
				if(i>=1&&a[i-1][j]&&a[i-1][j]!=c-'A'+1){
					s.insert(b[i-1][j]);
				}
				if(i<=n-2&&a[i+1][j]&&a[i+1][j]!=c-'A'+1){
					s.insert(b[i+1][j]);
				}
				if(j>=1&&a[i][j-1]&&a[i][j-1]!=c-'A'+1){
					s.insert(b[i][j-1]);
				}
				if(j<=m-2&&a[i][j+1]&&a[i][j+1]!=c-'A'+1){
					s.insert(b[i][j+1]);
				}
			}
		}
	}
	int ans=s.size();
	printf("%d",ans);
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while(t--){
        sol();
    }

    return 0;
}