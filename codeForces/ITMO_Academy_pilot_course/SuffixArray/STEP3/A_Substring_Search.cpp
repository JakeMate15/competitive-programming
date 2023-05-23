//https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/A
#include<bits/stdc++.h>

#define endl '\n'
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";

#define pb push_back

#define all(v) v.begin(), v.end()
#define sortall(f) sort(all(f))

#define forn(i,n) for(ll i=0;i<n;i++)

const int MX = 300005;

using namespace std;

typedef long long ll;

vector<int> res;
string s;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

void sol(){
    string q;
    cin>>q;
    string aux;

    int l=0,r=res.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        aux = s.substr(res[m],q.size());
        if(aux==q){
            YES
            return;
        }
        if(aux>q)   
            r=m-1;
        else    
            l=m+1;
    }

    NO
}

int main(){
    IO

    cin>>s;
    int t;cin>>t;
    res = suffix_array_construction(s);
    while(t--)
        sol();
    
    /*
    forn(i,s.size()){
        cout << s.substr(res[i],s.size()-res[i]) << endl;
    }
    cout << endl;
    */
    
}