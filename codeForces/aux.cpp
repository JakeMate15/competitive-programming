#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cerr << fixed << setprecision(5);

    int f = 0;
    double x, s = 0;
    map<double, int> cnt;
    vector<double> nums;
    while (cin >> x) {
        cnt[x]++;
        s += x;
        f++;
        nums.push_back(x);
    }

    // double media = s / f;
    // cerr << "s = " << s << " media = " << media << "\n";

    // double sq = 0;
    // for (auto &[v, r]: cnt) {
    //     cerr << (v - media) * (v - media) * r << "\n";
    //     sq += (v - media) * (v - media) * r;
    // }

    // double desviacion = sqrt(sq / (f - 1));
    // double z = (13.7 - media) / desviacion;
    // cerr << "cerr = " << z << "\n";

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        cout << i + 1 << ": " << nums[i] << "\n";
    }

    cerr << (nums[14] + nums[15]) / 2 << "\n";

    return 0;
}

/*

522
0.93122
14.17522
83.99722


*/