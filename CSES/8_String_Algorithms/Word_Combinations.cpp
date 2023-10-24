#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl              cout << "\n";
#define u_map           gp_hash_table
#define uid(a, b)       uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

struct Node{
  	bool isWord = false;
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
		}
		current->isWord = true;
	}

	bool FindWord(const string& word){
		Node* current = root;
		for(auto & c : word){
			if(!exists(current, c))
				return false;
			current = current->letters[c];
		}
		return current->isWord;
	}

	void printRec(Node * actual, string acum){
		if(actual->isWord){
			cout << acum << "\n";
		}
		for(auto & next : actual->letters)
			printRec(next.second, acum + next.first);
	}

	void printWords(const string & prefix){
		Node * actual = root;
		for(auto & c : prefix){
			if(!exists(actual, c)) return;
			actual = actual->letters[c];
		}
		printRec(actual, prefix);
	}
};


void sol(){
    string s;
    int q;
    cin >> s >> q;

    Trie t;
    t.InsertWord(s);

    while(q--) {
        cin >> s;
        t.InsertWord(s);
    }

    t.printWords("");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    //cin>>t;

    while(t--){
        sol();
    }

    return 0;
}