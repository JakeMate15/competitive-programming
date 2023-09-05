#include<bits/stdc++.h>
using namespace std;

#define IO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n)   for(int (i)=0; i<n; i++)
#define forr(i,a,n) for(int i=(a); i<n; i++)
#define fore(i,a,n) for(int i=(a); i<=n; i++)
#define all(v)	    v.begin(),v.end()
#define borra(s)    s.erase(unique(all(s)),s.end())
#define YES         cout << "YES\n"
#define NO          cout << "NO\n"
#define debug(a)    cout << a << "\n"
#define sz(a)       (int)a.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 1e9+7;


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

	T edmondsKarp(int s, int t){
		T maxFlow = 0;
		vector<flowEdge<T>*> parent(V);
		while(true){
			fill(parent.begin(), parent.end(), nullptr);
			queue<int> Q;
			Q.push(s);
			while(!Q.empty() && !parent[t]){
				int u = Q.front(); Q.pop();
				for(flowEdge<T> *v : adjList[u]){
					if(!parent[v->dest] && v->capacity > v->flow){
						parent[v->dest] = v;
						Q.push(v->dest);
					}
				}
			}
			if(!parent[t]) break;
			T f = inf;
			for(int u = t; u != s; u = parent[u]->res->dest)
				f = min(f, parent[u]->capacity - parent[u]->flow);
			for(int u = t; u != s; u = parent[u]->res->dest)
				parent[u]->addFlow(f);
			maxFlow += f;
		}
		return maxFlow;
	}
};


void sol(){
    int n,s,e;
    cin>>n>>s>>e;
    int prima;

    int t = n*2+1;
    flowGraph<ll> g(t+1);
    forn(i,s){
        int u;
        cin>>u;
        g.addEdge(0,u,1);
    }

    forn(i,e){
        int v;
        cin>>v;
        prima = v+n;
        g.addEdge(prima,t,1);
    }

    int m;
    cin>>m;

    fore(i,1,n)
        g.addEdge(i,i+n,1);

    forn(i,m){
        int u,v;
        cin>>u>>v;
        prima = u+n;
        g.addEdge(prima,v,1);
    }

    debug(g.dinic(0,t));

}

int main(){
	int t=1;
	//cin>>t;
	while(t--)  sol();
}