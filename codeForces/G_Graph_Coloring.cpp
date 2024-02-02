#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 1000043;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int sub(int x, int y)
{
    return add(x, -y);
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}                               

int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int global_hash = 0;

void reverse(deque<pair<int, int>>& d)
{
    stack<pair<int, int>> s;
    while(!d.empty())
    {
        s.push(d.back());
        d.pop_back();
    }
    while(!s.empty())
    {
        d.push_front(s.top());
        s.pop();
    }
}

void safe_push_front(deque<pair<int, int>>& d, int c, int& res)
{
    int z = d.front().first ^ 1;
    res = add(res, mul(binpow(2, c), z));
    d.push_front(make_pair(z, c));
}

void safe_push_back(deque<pair<int, int>>& d, int c, int& res)
{
    int z = d.back().first ^ 1;
    res = add(res, mul(binpow(2, c), z));
    d.push_back(make_pair(z, c));
}

deque<pair<int, int>> ds[N];

struct path
{
    int s;
    int t;
    int d;
    int c;

    path() {};
    path(int s, int t, int d, int c) : s(s), t(t), d(d), c(c) {};

    void push_front(int i)
    {
        safe_push_front(ds[d], i, c);
    }

    void push_back(int i)
    {
        safe_push_back(ds[d], i, c);
    }

    void pop_front()
    {
        ds[d].pop_front();
    }

    void pop_back()
    {
        ds[d].pop_back();
    }

    int front()
    {
        return ds[d].front().second;
    }

    int back()
    {
        return ds[d].back().second;
    }

    void reverse()
    {
        ::reverse(ds[d]);
        swap(s, t);
    }

    int size()
    {
        return ds[d].size();
    }
};

path link_to_left(path x, path y)
{
    path z = x;
    while(y.size() > 0)
    {
        z.push_back(y.front());
        y.pop_front();
    }
    z.t = y.t;
    return z;
}

path link_to_right(path x, path y)
{
    path z = y;
    while(x.size() > 0)
    {
        z.push_front(x.back());
        x.pop_back();
    }
    z.s = x.s;
    return z;
}

int cur = 0;

path make(int x, int y, int i)
{
    int cost = i;
    ds[cur].push_back(make_pair(0, cost));
    return path(x, y, cur++, 0);    
}

set<int> paths;
vector<int> paths_v[N];
path ps[N];

path merge(path x, path y, int v)
{
    if(x.size() > y.size())
        swap(x, y);
    if(y.s == v)
    {
        if(x.t != v)
            x.reverse();
        return link_to_right(x, y);    
    }
    else
    {
        if(x.s != v)
            x.reverse();
        return link_to_left(y, x);
    }    
}

int cur2 = 0;       

void modify(vector<int>& v, int x, int y)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i] == x)
            v[i] = y;
}   

void reassign(path p, int x, int y)
{
    modify(paths_v[p.s], x, y);
    modify(paths_v[p.t], x, y);    
}

void merge_paths(int x, int y, int v)
{
    if(x == y)
    {                         

    }
    else
    {
        global_hash = sub(global_hash, ps[x].c);
        global_hash = sub(global_hash, ps[y].c);
        ps[cur2++] = merge(ps[x], ps[y], v);
        paths.erase(x);
        paths.erase(y);
        paths.insert(cur2 - 1);
        reassign(ps[x], x, cur2 - 1);
        reassign(ps[y], y, cur2 - 1);
        global_hash = add(global_hash, ps[cur2 - 1].c);   
    }
}

void relax(int v)
{
    while(paths_v[v].size() >= 2)
    {
        int x = paths_v[v].back();
        paths_v[v].pop_back();
        int y = paths_v[v].back();
        paths_v[v].pop_back();
        merge_paths(x, y, v);
    }
}

void add_edge(int x, int y, int i)
{
    //cerr << x << " " << y << " " << i << endl;
    int c = cur2;
    ps[cur2++] = make(x, y, i);
    paths_v[x].push_back(c);
    paths_v[y].push_back(c);
    paths.insert(c);
    relax(x);
    relax(y);
}

void print_coloring()
{
    vector<int> ans;
    for(auto x : paths)
    {
        for(auto y : ds[ps[x].d])
        {
            if(y.first == 1)
                ans.push_back(y.second);
        }
    }
    printf("%d", int(ans.size()));
    for(auto x : ans)
        printf(" %d", x);
    puts("");
    fflush(stdout);
}

int e = 0;

void process_query()
{
    int t;
    scanf("%d", &t);
    if(t == 1)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        y += 200001;
        add_edge(x, y, ++e);
        printf("%d\n", global_hash);
        fflush(stdout);
    }
    else
        print_coloring();
}

void print_info()
{
    cerr << "Paths\n";
    for(auto x : paths)
        cerr << x << " start: " << ps[x].s << " " << " end: " << ps[x].t << endl;
    cerr << "Vertices\n";
    for(int i = 0; i < N; i++)
        if(!paths_v[i].empty())
        {
            cerr << i << ": ";
            for(auto x : paths_v[i])
                cerr << x << " ";
            cerr << endl;
        }

}
        
int main()
{
    int n1, n2, m;
    scanf("%d %d %d", &n1, &n2, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        y += 200001;
        add_edge(x, y, ++e);
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        //print_info();
        process_query();
    }
}