#include <iostream>
#include <utility>

const int MX = 1e5;
std::pair<int, int> st[MX * 2];

std::pair<int, int> aux(std::pair<int, int> a, std::pair<int, int> b){
    return {std::min(a.first,b.first), std::max(a.second,b.second)};
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        st[n + i] = {x, x};
    }
    for(int i = n - 1; i > 0; i--) {
        st[i] = aux(st[i << 1], st[i << 1 | 1]);
    }

    while(q--) {
        char i;
        int l, r;
        std::cin >> i >> l >> r;

        if(i == 'A') {
            l--;
            st[l += n] = {r, r};
            while(l >>= 1) 
                st[l] = aux(st[l << 1], st[l << 1 | 1]);
        }
        else {
            r--, l--;
            std::pair<int, int> res = {(1 << 30 - 1), -1};
            for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
                if(l & 1)    res = aux(st[l++], res);
                if(!(r & 1)) res = aux(st[r--], res);
            }
            std::cout << res.first << " " << res.second << "\n";
        }
    }
    return 0;
}