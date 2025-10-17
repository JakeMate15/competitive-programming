#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct Point {
    ll x, y;
};
 
ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
 
ll fullArea2(const vector<Point> &poly) {
    int n = poly.size();
    ll area2 = 0;
    for (int i = 0; i < n; i++){
        int j = (i+1)%n;
        area2 += cross(poly[i], poly[j]);
    }
    return area2;
}
 
ll gapCost(const vector<Point>& poly, int i, int j) {
    ll sum = 0;
    for (int k = i; k < j; k++){
        sum += cross(poly[k], poly[k+1]);
    }
    return sum - cross(poly[i], poly[j]);
}
 
ll cyclicGapCost(const vector<Point>& poly, int i, int j) {
    int n = poly.size();
    if(i <= j)
        return gapCost(poly, i, j);
    else {
        ll cost1 = gapCost(poly, i, n-1);
        ll cost2 = gapCost(poly, 0, j);
        ll extra = cross(poly[n-1], poly[0]);
        return cost1 + cost2 + extra;
    }
}
 
ll earCost(const vector<Point>& poly, int k) {
    int n = poly.size();
    int prev = (k - 1 + n)%n;
    int nxt = (k + 1)%n;
    ll c = cross(poly[prev], poly[k]) + cross(poly[k], poly[nxt]) - cross(poly[prev], poly[nxt]);
    return c;
}
 
ll adjPairCost(const vector<Point>& poly, int k) {
    int n = poly.size();
    int prev = (k - 1 + n)%n;
    int nxt = (k + 2)%n;
    ll c = cross(poly[prev], poly[k]) + cross(poly[k], poly[(k+1)%n]) + cross(poly[(k+1)%n], poly[nxt]) - cross(poly[prev], poly[nxt]);
    return c;
}
 
// --- Brute-force (n <= 20) ---
 
ll subpolyArea2(const vector<Point>& poly, const vector<int>& keep) {
    int m = keep.size();
    ll area = 0;
    for (int i = 0; i < m; i++){
        int a = keep[i], b = keep[(i+1)%m];
        area += cyclicGapCost(poly, a, b);
    }
    return area;
}
 
vector<ll> bruteCandidates;
 
void bruteEnumerate(const vector<Point>& poly, int idx, vector<int>& sel) {
    int n = poly.size();
    if(idx==n){
        if(sel.size()>=3){
            ll subArea = subpolyArea2(poly, sel);
            ll loss = fullArea2(poly) - subArea;
            bruteCandidates.push_back(loss);
        }
        return;
    }
    sel.push_back(idx);
    bruteEnumerate(poly, idx+1, sel);
    sel.pop_back();
    bruteEnumerate(poly, idx+1, sel);
}
 
// --- k–smallest pairs (for non–adjacent r=2 candidates) ---
 
struct Pair {
    ll sum;
    int i, j;
};
 
struct PairComp {
    bool operator()(const Pair &a, const Pair &b) {
        return a.sum > b.sum;
    }
};
 
vector<ll> kSmallestPairs(const vector<pair<ll,int>> &arr, int k, int modN) {
    vector<ll> res;
    int sz = arr.size();
    if(sz < 2) return res;
    priority_queue<Pair, vector<Pair>, PairComp> pq;
    for (int i = 0; i < sz; i++){
        if(i+1 < sz) {
            int idx1 = arr[i].second, idx2 = arr[i+1].second;
            bool valid = true;
            if(((idx1+1) % modN) == idx2) valid = false;
            if(idx1==0 && idx2==modN-1) valid = false;
            if(valid)
                pq.push({arr[i].first + arr[i+1].first, i, i+1});
        }
    }
    while(!pq.empty() && (int)res.size() < k){
        Pair cur = pq.top(); pq.pop();
        res.push_back(cur.sum);
        if(cur.j+1 < sz){
            int idx1 = arr[cur.i].second, idx2 = arr[cur.j+1].second;
            bool valid = true;
            if(((idx1+1) % modN)== idx2) valid = false;
            if(idx1==0 && idx2==modN-1) valid = false;
            pq.push({arr[cur.i].first + arr[cur.j+1].first, cur.i, cur.j+1});
        }
    }
    return res;
}
 
// --- Main ---
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++){
        cin >> poly[i].x >> poly[i].y;
    }
    ll fullA = fullArea2(poly);
    const int LIMIT = 200000;
    vector<ll> candLosses;
 
    if(n <= 20){
        vector<int> sel;
        bruteEnumerate(poly, 0, sel);
        sort(bruteCandidates.begin(), bruteCandidates.end());
        int m = bruteCandidates.size();
        if(m > LIMIT) m = LIMIT;
        cout << m << "\n";
        vector<ll> out(m);
        for (int i = 0; i < m; i++){
            ll area2 = fullA - bruteCandidates[i];
            out[i] = area2;
        }
        sort(out.begin(), out.end(), greater<ll>());
        for (int i = 0; i < m; i++){
            ll a2 = out[i];
            cout << (a2/2) << (a2 % 2 == 0 ? ".0" : ".5") << (i==m-1?"\n":" ");
        }
        return 0;
    }
 
    // For n > 20, we decide based on 1 + n.
    if(1 + n >= LIMIT){
        candLosses.push_back(0);
        for (int i = 0; i < n; i++){
            ll ec = earCost(poly, i);
            candLosses.push_back(ec);
        }
    } else {
        candLosses.push_back(0);
        vector<ll> r1;
        for (int i = 0; i < n; i++){
            ll ec = earCost(poly, i);
            r1.push_back(ec);
            candLosses.push_back(ec);
        }
        vector<pair<ll,int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({r1[i], i});
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){ return a.first < b.first; });
        int needed = LIMIT - (1 + n);
        vector<ll> r2NonAdj = kSmallestPairs(arr, needed, n);
        vector<ll> r2Adj;
        for (int i = 0; i < n; i++){
            ll cost = adjPairCost(poly, i);
            r2Adj.push_back(cost);
        }
        sort(r2Adj.begin(), r2Adj.end());
        vector<ll> r2;
        int i1 = 0, i2 = 0;
        while((i1 < (int)r2NonAdj.size() || i2 < (int)r2Adj.size()) && (int)r2.size() < needed){
            ll v1 = (i1 < (int)r2NonAdj.size() ? r2NonAdj[i1] : LLONG_MAX);
            ll v2 = (i2 < (int)r2Adj.size() ? r2Adj[i2] : LLONG_MAX);
            if(v1 < v2){
                r2.push_back(v1);
                i1++;
            } else {
                r2.push_back(v2);
                i2++;
            }
        }
        for(auto &val : r2)
            candLosses.push_back(val);
    }
    sort(candLosses.begin(), candLosses.end());
    int tot = candLosses.size();
    int m = tot;
    if(m > LIMIT) m = LIMIT;
    vector<ll> out;
    for (int i = 0; i < m; i++){
        out.push_back(fullA - candLosses[i]);
    }
    sort(out.begin(), out.end(), greater<ll>());
    cout << m << "\n";
    for (int i = 0; i < m; i++){
        ll a2 = out[i];
        cout << (a2/2) << (a2 % 2 == 0 ? ".0" : ".5") << (i==m-1 ? "\n" : " ");
    }
    return 0;
}
