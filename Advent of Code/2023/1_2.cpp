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

struct kmp{
	vector<int> aux;
	string pattern;

	kmp(string pattern){
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

	vector<int> search(string & text){
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


void sol(){
    string s;

	vector<pair<string, int>> numbers = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
        {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}};

	ll res = 0;
    while(cin >> s) {
		map<int, int> nc;
		for(auto [n, nInt]: numbers) {
			kmp k(n);
			auto res = k.search(s);

			for(auto x: res) {
				nc[x] = nInt;
			}
		}
		res += (*nc.begin()).second * 10 + (*prev(nc.end())).second;
    }

	cout << res << "\n";
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