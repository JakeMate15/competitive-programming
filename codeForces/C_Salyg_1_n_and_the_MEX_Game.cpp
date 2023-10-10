#include<bits/stdc++.h>
using namespace std;

#define all(v)          v.begin(),v.end()
#define sz(a)           (int)a.size()
#define debln(a)        cout << a << "\n"
#define deb(a)          cout << a << " "
#define nl()            cout << "\n"
typedef long long ll;

void sol(){
    int n;
    cin >> n;

    set<int> nums;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.insert(x);
    }

    int mex = 0;
    while(nums.count(mex)) {
        mex++;
    }

    while(mex != -1) {
        debln(mex);
        cin >> mex;
    }
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }

    return 0;
}