#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> dias = {1, 4, 9, 16, 25};
    vector<int> meses = {1, 4, 9};
    vector<int> arr = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int res = 0;
    for(int i = a; i <= b; i++) {
        int sq = sqrt(i);
        if(sq * sq == i){
            for(int m: meses){
                if(m <= 12){
                    for(int d: dias){
                        if(d <= arr[m]) res++;
                    }
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}