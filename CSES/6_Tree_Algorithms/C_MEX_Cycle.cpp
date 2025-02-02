#include <bits/stdc++.h>
using namespace std;

// Function to check if the graph is bipartitionable
bool isBipartitionable(int n, vector<vector<int>> &adj, vector<int> &color, int &conflict_node) {
    color.assign(n + 1, -1);
    bool bipart = true;
    for(int node=1; node<=n; node++) {
        if(color[node]==-1){
            queue<int> q;
            q.push(node);
            color[node]=0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(auto &v: adj[u]){
                    if(color[v]==-1){
                        color[v] = color[u]^1;
                        q.push(v);
                    }
                    else if(color[v] == color[u]){
                        bipart = false;
                        conflict_node = u; // Record the conflicting node
                        return bipart;
                    }
                }
            }
        }
    }
    return bipart;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        // Build adjacency list
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=1; i<=n; i++){
            int next = (i % n) +1;
            int prev = (i-2+n)%n +1;
            adj[i].push_back(next);
            adj[i].push_back(prev);
        }
        // Check if x and y are adjacent
        bool adjacent = false;
        for(auto &v: adj[x]){
            if(v == y){
                adjacent = true;
                break;
            }
        }
        if(!adjacent){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // Check bipartition
        vector<int> color;
        int conflict_node = -1;
        bool bipart = isBipartitionable(n, adj, color, conflict_node);
        // Assign a_i
        vector<int> a(n+1, 0);
        if(bipart){
            for(int i=1; i<=n; i++) a[i] = color[i];
        }
        else{
            // Assign as per color
            for(int i=1; i<=n; i++) a[i] = color[i];
            // Assign 2 to one node with color 0
            // To ensure correctness, assign to the conflict_node
            // If conflict_node is -1, assign to node1
            int assign_node = conflict_node != -1 ? conflict_node : 1;
            // Ensure the node has color 0
            if(color[assign_node] !=0){
                // Find any node with color 0
                assign_node = -1;
                for(int i=1; i<=n; i++) {
                    if(color[i]==0){
                        assign_node = i;
                        break;
                    }
                }
                if(assign_node == -1){
                    // Should not happen, but assign to node1
                    assign_node =1;
                }
            }
            a[assign_node] = 2;
        }
        // Output the result
        for(int i=1; i<=n; i++) {
            cout << a[i] << (i<n ? ' ' : '\n');
        }
    }
}
