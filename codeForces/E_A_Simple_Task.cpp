#include<bits/stdc++.h>
using namespace std;
 
#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define nl              cout << "\n";
 
typedef long long ll;
typedef long double ld;
 
const int mod = 1e9 + 7;
const int MX = 2e5 + 5;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};
struct Tag {
    int add = 0; 

    void apply(const Tag &t) {
        add = (add + t.add) % 26; 
    }
};

struct Info {
    array<int, 26> freq{}; 

    void apply(const Tag &t) {
        if (t.add == 0) return;
        array<int, 26> newFreq{};
        for (int i = 0; i < 26; ++i) {
            newFreq[(i + t.add) % 26] = freq[i];
        }
        freq = newFreq;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info result;
    for (int i = 0; i < 26; ++i) {
        result.freq[i] = a.freq[i] + b.freq[i];
    }
    return result;
}


void sol() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i].freq[s[i] - 'a'] = 1;
    }

    LazySegmentTree<Info, Tag> ST;
    ST.init(init);

    while (q--) {
        int l, r, t;
        cin >> l >> r >> t;
        l--; r--;

        // Recoge las frecuencias de los caracteres en el rango
        Info queryResult = ST.rangeQuery(l, r);

        // Reordena los caracteres basado en el tipo de operación
        if (t == 1) {
            // Orden ascendente
            for (int j = 0; j < 26; j++) {
                if (queryResult.freq[j] > 0) {
                    ST.rangeApply(l, l + queryResult.freq[j], Tag{j});
                    l += queryResult.freq[j];
                }
            }
        } else {
            // Orden descendente
            for (int j = 25; j >= 0; j--) {
                if (queryResult.freq[j] > 0) {
                    ST.rangeApply(l, l + queryResult.freq[j], Tag{j});
                    l += queryResult.freq[j];
                }
            }
        }
    }

    // Reconstruye la cadena de caracteres
    for (int i = 0; i < n; i++) {
        Info singleCharInfo = ST.rangeQuery(i, i + 1);
        for (int j = 0; j < 26; j++) {
            if (singleCharInfo.freq[j] > 0) {
                cout << char('a' + j);
                break;
            }
        }
    }
    cout << endl;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << fixed << setprecision(10);

    int t=1;
    cin>>t;

    while(t--){
        sol();
    }

    return 0;
}