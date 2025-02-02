#include <bits/stdc++.h>
using namespace std;

static const long long INF = 1e15;

pair<long long,long long> getRangeAll(const vector<long long> &arr) {
    long long sum = 0, mx = -INF, mn = INF, curMax = 0, curMin = 0;
    for (auto x : arr) {
        sum += x;
        curMax = max((long long)x, curMax + x);
        mx = max(mx, curMax);
        curMin = min((long long)x, curMin + x);
        mn = min(mn, curMin);
    }
    return {mn, mx};
}

pair<long long,long long> getRangeEnding(const vector<long long> &arr) {
    if (arr.empty()) return {0,0};
    long long n = arr.size();
    vector<long long> p(n+1,0);
    for (int i=1; i<=n; i++) p[i] = p[i-1] + arr[i-1];
    long long all = p[n], mx = -INF, mn = INF;
    long long mxP = -INF, mnP = INF;
    for (int i=0; i<n; i++){
        mxP = max(mxP, p[i]);
        mnP = min(mnP, p[i]);
    }
    mx = all - mnP;
    mn = all - mxP;
    return {mn,mx};
}

pair<long long,long long> getRangeStarting(const vector<long long> &arr) {
    if (arr.empty()) return {0,0};
    long long n = arr.size();
    long long cur = 0, mx = -INF, mn = INF;
    for (auto x : arr) {
        cur += x;
        mx = max(mx, cur);
        mn = min(mn, cur);
    }
    return {mn, mx};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int outlierPos = -1;
        for(int i=0; i<n; i++){
            if(a[i]!=1 && a[i]!=-1){
                outlierPos = i;
                break;
            }
        }

        if(outlierPos==-1){
            auto rng = getRangeAll(a);
            long long start = min(0LL, rng.first), end = max(0LL, rng.second);
            cout << (end - start + 1) << "\n";
            for(long long val=start; val<=end; val++){
                cout << val << (val<end?' ':'\n');
            }
            continue;
        }

        long long x = a[outlierPos];
        vector<long long> leftPart(a.begin(), a.begin()+outlierPos);
        vector<long long> rightPart(a.begin()+outlierPos+1, a.end());

        pair<long long,long long> lAll={0,0}, rAll={0,0};
        if(!leftPart.empty()) lAll = getRangeAll(leftPart);
        if(!rightPart.empty()) rAll = getRangeAll(rightPart);

        pair<long long,long long> lEnd={0,0}, rStart={0,0};
        if(!leftPart.empty()) lEnd = getRangeEnding(leftPart);
        if(!rightPart.empty()) rStart = getRangeStarting(rightPart);

        set<pair<long long,long long>> intervals;
        intervals.insert({min(0LL, lAll.first), max(0LL, lAll.second)});
        intervals.insert({min(0LL, rAll.first), max(0LL, rAll.second)});
        long long minVal = lEnd.first + x + rStart.first;
        long long maxVal = lEnd.second + x + rStart.second;
        intervals.insert({min(minVal,0LL), max(maxVal,0LL)});

        vector<pair<long long,long long>> merged;
        {
            vector<pair<long long,long long>> vals;
            for(auto &p: intervals) vals.push_back(p);
            sort(vals.begin(), vals.end());
            long long st = vals[0].first, en = vals[0].second;
            for(int i=1; i<(int)vals.size(); i++){
                if(vals[i].first<=en+1){
                    en = max(en, vals[i].second);
                } else {
                    merged.push_back({st,en});
                    st=vals[i].first; en=vals[i].second;
                }
            }
            merged.push_back({st,en});
        }

        long long countAll=0;
        for(auto &iv: merged) countAll += (iv.second - iv.first + 1);
        cout << countAll << "\n";
        bool firstPrint=true;
        for(auto &iv: merged){
            for(long long val=iv.first; val<=iv.second; val++){
                if(!firstPrint) cout<<" ";
                cout<<val;
                firstPrint=false;
            }
        }
        cout<<"\n";
    }
    return 0;
}
