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

    int a[n+1]={0},b[m+1]={0};
    fore(i,1,n)   cin>>a[i];
    fore(i,1,m)   cin>>b[i];

    vector<int> patron(n-1),busqueda(m-1);
    fore(i,0,n-1) patron[i] = abs(a[i+1]-a[i+2]);
    fore(i,0,m-1) busqueda[i] = abs(b[i+1]-b[i+2]);

    kmp k(patron);
    vector<int> bK = k.search(busqueda);
    debug(bK.size());
}