#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

template<typename T>
struct flowEdge{
    int dest;
    T flow, capacity, cost;
    flowEdge *res;

    flowEdge(): dest(0), flow(0), capacity(0), cost(0), res(NULL){}
    flowEdge(int dest, T flow, T capacity, T cost = 0): dest(dest), flow(flow), capacity(capacity), cost(cost), res(NULL){}

    void addFlow(T flow){
        this->flow += flow;
        this->res->flow -= flow;
    }
};

template<typename T>
struct flowGraph{
    T inf = numeric_limits<T>::max();
    vector<vector<flowEdge<T>*>> adjList;
    vector<int> dist, pos;
    int V;
    flowGraph(int V): V(V), adjList(V), dist(V), pos(V){}
    ~flowGraph(){
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < adjList[i].size(); ++j)
                delete adjList[i][j];
    }
    void addEdge(int u, int v, T capacity, T cost = 0){
        flowEdge<T> *uv = new flowEdge<T>(v, 0, capacity, cost);
        flowEdge<T> *vu = new flowEdge<T>(u, capacity, capacity, -cost);
        uv->res = vu;
        vu->res = uv;
        adjList[u].push_back(uv);
        adjList[v].push_back(vu);
    }

    //Maximun Flow using Dinic Algorithm O(EV^2)
    T blockingFlow(int u, int t, T flow){
        if(u == t) return flow;
        for(int &i = pos[u]; i < adjList[u].size(); ++i){
            flowEdge<T> *v = adjList[u][i];
            if(v->capacity > v->flow && dist[u] + 1 == dist[v->dest]){
                T fv = blockingFlow(v->dest, t, min(flow, v->capacity - v->flow));
                if(fv > 0){
                    v->addFlow(fv);
                    return fv;
                }
            }
        }
        return 0;
    }
    T dinic(int s, int t){
        T maxFlow = 0;
        dist[t] = 0;
        while(dist[t] != -1){
            fill(dist.begin(), dist.end(), -1);
            queue<int> Q;
            Q.push(s);
            dist[s] = 0;
            while(!Q.empty()){
                int u = Q.front(); Q.pop();
                for(flowEdge<T> *v : adjList[u]){
                    if(dist[v->dest] == -1 && v->flow != v->capacity){
                        dist[v->dest] = dist[u] + 1;
                        Q.push(v->dest);
                    }
                }
            }
            if(dist[t] != -1){
                T f;
                fill(pos.begin(), pos.end(), 0);
                while(f = blockingFlow(s, t, inf))
                    maxFlow += f;
            }
        }
        return maxFlow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> caballos(m);
    for (auto &[a, b]: caballos) 
        cin >> a >> b;


    function<bool(int, int)> atacan = [&] (int i, int j) -> bool {
        auto [x1, y1] = caballos[i];
        auto [x2, y2] = caballos[j];

        for (int i = 0; i < 8; ++i) {
            if (x1 + dx[i] == x2 && y1 + dy[i] == y2) {
                return true;
            }
        }
        return false;
    };

    flowGraph<int> dn (m + 2);
    int s = m, t = m + 1;

    for (int i = 0; i < m; i++) {
        auto [x, y] = caballos[i];
        for (int j = i + 1; j < m; j++) {
            if (atacan(i, j)) {
                if ((x + y) % 2 == 0) {
                    dn.addEdge(i, j, 1);
                }
                else {
                    dn.addEdge(j, i, 1);
                }
            }
        }

        if ((x + y) % 2 == 0) {
            dn.addEdge(s, i, 1);
        }
        else {
            dn.addEdge(i, t, 1);
        }
    }

    cout << dn.dinic(s, t);
    

    return 0;
}