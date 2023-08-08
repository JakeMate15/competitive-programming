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


const int M = 26;
struct node{
	vector<int> child;
	int p = -1;
	char c = 0;
	int suffixLink = -1, endLink = -1;
	int id = -1;

	node(int p = -1, char c = 0) : p(p), c(c){
		child.resize(M, -1);
	}
};

struct AhoCorasick{
	vector<node> t;
	vector<int> lenghts;
	int wordCount = 0;

	AhoCorasick(){
		t.emplace_back();
	}

	void add(const string & s){
		int u = 0;
		for(char c : s){
			if(t[u].child[c-'a'] == -1){
				t[u].child[c-'a'] = t.size();
				t.emplace_back(u, c);
			}
			u = t[u].child[c-'a'];
		}
		t[u].id = wordCount++;
		lenghts.push_back(s.size());
	}

	void link(int u){
		if(u == 0){
			t[u].suffixLink = 0;
			t[u].endLink = 0;
			return;
		}
		if(t[u].p == 0){
			t[u].suffixLink = 0;
			if(t[u].id != -1) t[u].endLink = u;
			else t[u].endLink = t[t[u].suffixLink].endLink;
			return;
		}
		int v = t[t[u].p].suffixLink;
		char c = t[u].c;
		while(true){
			if(t[v].child[c-'a'] != -1){
				t[u].suffixLink = t[v].child[c-'a'];
				break;
			}
			if(v == 0){
				t[u].suffixLink = 0;
				break;
			}
			v = t[v].suffixLink;
		}
		if(t[u].id != -1) t[u].endLink = u;
		else t[u].endLink = t[t[u].suffixLink].endLink;
	}

	void build(){
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			link(u);
			for(int v = 0; v < M; ++v)
				if(t[u].child[v] != -1)
					Q.push(t[u].child[v]);
		}
	}

	int match(const string & text){
		int u = 0;
		int ans = 0;
                set<int> res;
		for(int j = 0; j < text.size(); ++j){
			int i = text[j] - 'a';
			while(true){
				if(t[u].child[i] != -1){
					u = t[u].child[i];
					break;
				}
				if(u == 0) break;
				u = t[u].suffixLink;
			}
			int v = u;
			while(true){
				v = t[v].endLink;
				if(v == 0) break;
				++ans;
				int idx = j + 1 - lenghts[t[v].id];
				cout << "Found word #" << t[v].id << " at position " << idx << "\n";
				v = t[v].suffixLink;
			}
		}
		return ans;
	}
};

void sol(){
        int n;
        cin>>n;

        AhoCorasick a,b;
        bool inv = false;
        string s;
        

        vector<string> pend;
        vi res;
        while(n--){
                int op;
                cin>>op;

                if(op==1){
                        cin>>
                        //Procesar los faltantes


                }

        }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}