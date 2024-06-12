#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sol() {
    int x, y;
    cin >> x >> y;

    bitset<32> binX(x);
    bitset<32> binY(y);

    string strX = binX.to_string();
    string strY = binY.to_string();

    int cnt = 0;
    for (int i = strX.size() - 1; i >= 0; i--) {
        if (strX[i] != strY[i])
            break;
        cnt++;
    }

    cout << (1 << cnt) << "\n";
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