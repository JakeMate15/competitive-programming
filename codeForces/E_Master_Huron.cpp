#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    double d, p, e;
    cin >> d >> p >> e;
    vector<int> b(n);
    for(auto &x: b) cin >> x;
    sort(b.begin(), b.end());
    vector<double> pre_sum_inv(n+1, 0.0);
    for(int i=1;i<=n;i++) pre_sum_inv[i] = pre_sum_inv[i-1] + 1.0 / b[i-1];
    auto compute_E = [&](double a) -> double {
        double E =0.0;
        double da = d * a;
        int k_d = upper_bound(b.begin(), b.end(), da) - b.begin();
        double sum_d = pre_sum_inv[n] - pre_sum_inv[k_d];
        double k_1 = upper_bound(b.begin(), b.end(), a) - b.begin();
        double sum_1 = pre_sum_inv[n] - pre_sum_inv[k_1];
        E = p * (k_d + da * sum_d) + (1.0 - p) * (k_1 + a * sum_1);
        return E;
    };
    if(e ==0.0){
        cout << fixed << setprecision(10) << "0\n";
        return 0;
    }
    double lo=0.0, hi=1e14;
    for(int i=0;i<100;i++){
        double mid=(lo + hi)/2.0;
        double E = compute_E(mid);
        if(E >= e) hi=mid;
        else lo=mid;
    }
    double a = hi;
    // To handle cases where e is exactly n
    if(e >= n){
        double max_b = *max_element(b.begin(), b.end());
        a = max(max_b / d, max_b *1.0);
    }
    cout << fixed << setprecision(12) << a;
}
