#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(lli (i)=0; i<n; i++)
#define forr(i,a,n) for(lli i=(a); i<n; i++)
#define fore(i,a,n) for(lli i=(a); i<=n; i++)
#define all(v)      v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"


/*
v = [int(i) for i in input().split(" ")]

a = v[0]
b = v[1]
x = v[2]

lastv = -1
if b > a:
	lastv = 1
	print(1, end="")
	b -= 1
else:
	lastv = 0
	print(0, end="")
	a -= 1

while x > 1:
	x -= 1
	if lastv == 0:
		print(1, end="")
		lastv = 1
		b -= 1
	else:
		print(0, end="")
		lastv = 0
		a -= 1

if lastv == 1:
	while b > 0:
		print(1, end="")
		b -= 1
	while a > 0:
		print(0, end="")
		a -= 1

else:
	while a > 0:
		print(0, end="")
		a -= 1
	while b > 0:
		print(1, end="")
		b -= 1
	
print()
*/

void sol(){
	int a,b,x;
	cin>>a>>b>>x;

	int flag = -1;

	if(b>a){
		flag = 1;
		cout<<1;
		b--;
	}
	else{
		flag = 0;
		cout << 0;
		a--;
	}

	while(x>1){
		x--;
		if(flag==0){
			cout << 1;
			flag = 1;
			b--;
		}
		else{
			cout << 0;
			flag = 0;
			a--;
		}
	}

	if(flag==1){
		while(b>0){
			cout << 1;
			b--;
		}
		while(a>0){
			cout << 0;
			a--;
		}
	}
	else{
		while(a>0){
			cout << 0;
			a--;
		}
		while(b>0){
			cout << 1;
			b--;
		}
	}

	/*
	if lastv == 1:
	while b > 0:
		print(1, end="")
		b -= 1
	while a > 0:
		print(0, end="")
		a -= 1

	else:
		while a > 0:
			print(0, end="")
			a -= 1
		while b > 0:
			print(1, end="")
			b -= 1
	*/
}

int main(){IO
    int t=1;
    cin>>t;
    while(t--)  sol();
}