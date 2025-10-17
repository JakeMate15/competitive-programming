#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2000000000000000000LL;
map<ll, pair<ll, ll>> seg;
 
void split(ll pos) {
    auto it = seg.upper_bound(pos);
    if(it == seg.begin())
        return;
    it--;
    ll l = it->first, r = it->second.first, h = it->second.second;
    if(l == pos || r < pos)
        return;
    seg.erase(it);
    seg[l] = {pos - 1, h};
    seg[pos] = {r, h};
}
 
void merge(ll pos) {
    auto it = seg.find(pos);
    if(it == seg.end()) 
        return;
    if(it != seg.begin()){
        auto prev = it; prev--;
        if(prev->second.second == it->second.second && prev->second.first + 1 == it->first){
            ll newL = prev->first, newR = it->second.first, h = it->second.second;
            seg.erase(prev);
            seg.erase(it);
            seg[newL] = {newR, h};
            it = seg.find(newL);
        }
    }
    auto nxt = it; nxt++;
    if(nxt != seg.end()){
        if(it->second.second == nxt->second.second && it->second.first + 1 == nxt->first){
            ll newL = it->first, newR = nxt->second.first, h = it->second.second;
            seg.erase(it);
            seg.erase(nxt);
            seg[newL] = {newR, h};
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    seg[1] = {INF, 0};
    string ans(n, '-');

    for (int i = 0; i < n; i++){
        char op;
        ll L, P;
        cin >> op >> L >> P;

        if(op == '|'){
            split(P);
            split(P + 1);
            auto it = seg.find(P);
            ll cur = it->second.second;
            ll newH = cur + L;
            it->second.second = newH;
            merge(P);
            ans[i] = 'S';
        } else {
            ll start = P, end = P + L - 1;
            split(start);
            split(end + 1);
            auto it = seg.lower_bound(start);
            bool uniform = true;
            ll base = it->second.second;
            for(; it != seg.end() && it->first <= end; it++){
                if(it->second.second != base){ 
                    uniform = false; 
                    break; 
                }
            }
            if(!uniform){
                ans[i] = 'U';
            } else {
                ans[i] = 'S';
                ll newVal = base + 1;
                auto it2 = seg.lower_bound(start);
                vector<ll> keys;
                while(it2 != seg.end() && it2->first <= end){
                    keys.push_back(it2->first);
                    it2++;
                }
                for(auto key : keys) seg.erase(key);
                seg[start] = {end, newVal};
                merge(start);
                split(end + 1);
                merge(end + 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
