#include<bits/stdc++.h>
using namespace std;

#define all(a)  a.begin(), a.end()

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, t;
    cin >> n >> l >> t;

    vector<vector<int>> lin(l + 1);
    vector<vector<int>> est(n + 1);
    vector<vector<int>> posLin(l+1, vector<int>(n + 1, -1));
    for(int i = 1; i <= l; i++){
        int ki;
        cin >> ki;

        lin[i].resize(ki);
        for(int j = 0; j < ki; j++){
            cin >> lin[i][j];
            est[lin[i][j]].push_back(i);
            posLin[i][lin[i][j]] = j;
        }
    }

    const int INF = 1e9;
    vector<vector<int>> dist(n + 1, vector<int>(l + 1, INF));
    dist[1][1] = 0;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, std::greater<>> pq;
    pq.push({0, {1, 1}});
    while(!pq.empty()){
        auto curr = pq.top(); 
        pq.pop();

        int tmp = curr.first;
        int s = curr.second.first;
        int l = curr.second.second;
        if(tmp > dist[s][l]) 
            continue;

        int pos = posLin[l][s];
        if(pos != -1){
            if(pos > 0){
                int ant = lin[l][pos - 1];
                if(tmp + t < dist[ant][l]){
                    dist[ant][l] = tmp + t;
                    pq.push({dist[ant][l], {ant, l}});
                }
            }
            if(pos < (int)lin[l].size() - 1){
                int sig = lin[l][pos + 1];
                if(tmp + t < dist[sig][l]){
                    dist[sig][l] = tmp + t;
                    pq.push({dist[sig][l], {sig, l}});
                }
            }
        }

        for(auto &m: est[s]){
            if(m != l){
                if(tmp + t < dist[s][m]){
                    dist[s][m] = tmp + t;
                    pq.push({dist[s][m], {s, m}});
                }
            }
        }
    }

    vector<int> min_tmp(n + 1, INF);
    for(int s = 1; s <= n; s++) {
        for(int m = 1; m <= l; m++) {
            min_tmp[s] = min(min_tmp[s], dist[s][m]);
        }
    }

    for(int s = 1; s <= n;s++) {
        if(min_tmp[s] == INF) {
            cout << "-1 ";
        } else {
            cout << min_tmp[s] << " ";
        }
    }

    return 0;
}
