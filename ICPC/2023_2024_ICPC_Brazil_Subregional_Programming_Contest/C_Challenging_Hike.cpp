#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1000;

int N;
int S[MAX_N + 1];
vector<int> adj[MAX_N + 1];
int global_max_lis = 0;

void dfs(int current, int parent, vector<int> &current_lis) {
    int pos = lower_bound(current_lis.begin(), current_lis.end(), S[current]) - current_lis.begin();
    vector<int> backup = current_lis;
    if (pos == current_lis.size()) {
        current_lis.push_back(S[current]);
    }
    else {
        current_lis[pos] = S[current];
    }
    global_max_lis = max(global_max_lis, (int)current_lis.size());
    for(auto &neighbor : adj[current]) {
        if(neighbor != parent){
            dfs(neighbor, current, current_lis);
        }
    }
    current_lis = backup;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> S[i];
    }
    for(int i=0;i<N-1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=N;i++) {
        vector<int> current_lis;
        dfs(i, -1, current_lis);
    }
    cout << global_max_lis;
    return 0;
}

