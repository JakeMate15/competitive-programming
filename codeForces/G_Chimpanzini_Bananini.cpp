#include<bits/stdc++.h>
using namespace std;

void sol () {
    int q;
    cin >> q;

    deque<int> dq;
    bool dir = false;
    int64_t sum = 0, sum1 = 0, sum2 = 0;
    
    while(q--) {
        int op;
        cin >> op;

        int n = dq.size();
        if(op == 1) {
            int x;
            if(!dir) {
                x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            } else {
                x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
            sum1 += sum - 1LL * n * x;
            sum2 += n * 1LL * x - sum;
        } else if(op == 2) {
            dir = !dir;
            swap(sum1, sum2);
        } else {
            int x;
            cin >> x;
            sum1 += 1LL * x * (n + 1);
            sum2 += sum + x;
            sum += x;
            if(!dir)
                dq.push_back(x);
            else
                dq.push_front(x);
        }
        cout << sum1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}