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

struct kmp{
	vector<int> aux,pattern;

	kmp(vector<int> pattern){
		this->pattern = pattern;
		aux.resize(pattern.size());
		int i = 1, j = 0;
		while(i < pattern.size()){
			if(pattern[i] == pattern[j])
				aux[i++] = ++j;
			else{
				if(j == 0) aux[i++] = 0;
				else j = aux[j - 1];
			}
		}
	}

	vector<int> search(vector<int> & text){
		vector<int> ans;
		int i = 0, j = 0;
		while(i < text.size() && j < pattern.size()){
			if(text[i] == pattern[j]){
				++i, ++j;
				if(j == pattern.size()){
					ans.push_back(i - j);
					j = aux[j - 1];
				}
			}else{
				if(j == 0) ++i;
				else j = aux[j - 1];
			}
		}
		return ans;
	}
};

int main(){IO
    int n,m;
    cin>>n>>m;

	if(n==1){
		cout << m << "\n";
		return 0;
	}

    int a[n]={0},b[m]={0};
    forn(i,n)   cin>>a[i];
    forn(i,m)   cin>>b[i];

    vector<int> patron,busqueda;
    forr(i,1,n) patron.push_back(a[i]-a[i-1]);
    forr(i,1,m) busqueda.push_back(b[i]-b[i-1]);

    kmp k(patron);
    vector<int> bK = k.search(busqueda);
    debug(bK.size());
}