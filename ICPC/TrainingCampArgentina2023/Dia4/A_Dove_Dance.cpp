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

struct Node{
  	bool isWord = true;
	map<char, Node*> letters;
};

struct Trie{
	Node* root;

	Trie(){
		root = new Node();
	}

	inline bool exists(Node * actual, const char & c){
		return actual->letters.find(c) != actual->letters.end();
	}

	void InsertWord(const string& word){
		Node* current = root;
		for(auto & c : word){
			if(!exists(current, c))
				current->letters[c] = new Node();
			current = current->letters[c];
                        //current->isWord = true;
		}
		//current->isWord = true;
	}

	bool FindWord(const string& word){
		Node* current = root;
		for(auto & c : word){
                        //cout << c << " ";
			if(!exists(current, c))
				return false;
			current = current->letters[c];
		}
		return current->isWord;
	}
};

void sol(){
        int n;
        cin>>n;

        int op;
        string s;
        Trie t,t2;

        bool inv = false;
        while(n--){
                cin>>op;

                if(op==1){
                        cin>>s;
                        
                        if(inv){
                                t2.InsertWord(s);
                                reverse(all(s));
                                t.InsertWord(s);
                        }
                        else{
                                t.InsertWord(s);
                                reverse(all(s));
                                //debug(s);
                                t2.InsertWord(s);
                        }
                }
                else if(op==2){
                        cin>>s;
                        //debug( (to_string(inv) + "nc"));
                        if(inv){
                                if(t2.FindWord(s)){
                                        debug(1);
                                }
                                else{
                                        debug(0);
                                }
                        }
                        else{
                                if(t.FindWord(s)){
                                        debug(1);
                                }
                                else{
                                        debug(0);
                                }
                        }
                }
                else{
                        inv^=1;
                }
        }
}

int main(){IO
    int t=1;
    //cin>>t;
    while(t--)  sol();
}