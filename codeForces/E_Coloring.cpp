#include<bits/stdc++.h>
using namespace std;

#define forn(i,n)       for(int i=0; i<n; i++)
#define forr(i,a,n)     for(int i=a; i<n; i++)
#define fore(i,a,n)     for(int i=a; i<=n; i++)
#define fornd(i,n)      for(int i=n; i>=0; i--)
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define pb              push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

typedef long long intl;
const intl MOD = 998244353;
const int MAXN = 1e6 + 10;
 
set <int> bad[2];
set <int> unico[2];
map <int, int> contador[2][2][2];
map <pair<int,int>, int> table;
 
void update(int dir, int number){
	if(min(contador[dir][0][0][number],contador[dir][1][0][number]) > 0 or
		min(contador[dir][0][1][number],contador[dir][1][1][number]) > 0 or
		min(contador[dir][0][0][number],contador[dir][0][1][number]) > 0 or
		min(contador[dir][1][0][number],contador[dir][1][1][number]) > 0){
		unico[dir].erase(number);
		bad[dir].insert(number);
	}
	else if(contador[dir][0][0][number] + contador[dir][1][0][number] > 0 || 
			contador[dir][0][1][number] + contador[dir][1][1][number] > 0){
		bad[dir].erase(number);
		unico[dir].insert(number);
	}
	else{
		bad[dir].erase(number);
		unico[dir].erase(number);
	}
}
int cantidadparidad[2][2];
void updateContador(int x, int y, int last, int sumar){
	contador[0][y%2][last][x]+=sumar;
	contador[1][x%2][last][y]+= sumar;
	cantidadparidad[(y%2 + x%2)%2][last]+= sumar;
	update(0, x);
	update(1, y);
}
 

void sol(){
	vector <intl> pow2(MAXN, 1);
	forr(i, 1, MAXN){
		pow2[i] = (pow2[i-1]*2)%MOD;
	}
	int n,m,q;
	cin>>n>>m>>q;
	while(q--){
		int x,y,t;
		cin>>x>>y>>t;
		if(t == -1){
			if(table.count({x,y})){
				int last = table[{x,y}];
				table.erase({x,y});
				updateContador(x,y,last,-1);
			}
		}
		else if(t == 0){
			if(table.count({x,y})){
				int last = table[{x,y}];
				updateContador(x,y,last,-1);
				updateContador(x,y,0, 1);
			}	
			else{
				updateContador(x,y,0, 1);
 
			}
			table[{x,y}] = 0;
		}
		else{
			if(table.count({x,y})){
				//debln("aa");
				int last = table[{x,y}];
				updateContador(x,y,last,-1);
				updateContador(x,y,1, 1);
			}	
			else{
				updateContador(x,y,1, 1);
			}
			table[{x,y}] = 1;
		}
		int n1 = unico[0].size();
		int m1 = unico[1].size();
		int restar = 2;
		if(min(cantidadparidad[0][0],cantidadparidad[1][0]) > 0 or 
			min(cantidadparidad[0][1],cantidadparidad[1][1]) > 0 or
			min(cantidadparidad[1][0],cantidadparidad[1][1]) > 0 or
			min(cantidadparidad[0][0],cantidadparidad[0][1]) > 0 ){
				restar = 0;
			}
			
		//debln(sz(unico[0]));
		else if(unico[0].size() > 0){
			restar--;
			//debln("kk");
		}
		intl res1 = pow2[n - n1], res2 = pow2[m - m1];
		if(bad[0].size() > 0){
			res1 = 0;
		}
		if(bad[1].size() > 0){
			res2 = 0;
		}
        //deb(n1);debln(m1);
		//debln(restar);
		debln((res1 + res2 - restar + MOD) %MOD);
	}
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        sol();
    }

    return 0;
}