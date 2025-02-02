#include <bits/stdc++.h>
using namespace std;

// Function to compute GCD
long long compute_gcd(long long a, long long b){
    while(b){
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        long long l, r, G;
        cin >> l >> r >> G;
        
        // Compute k_min = ceil(l / G)
        // To avoid floating point, use (l + G -1) / G
        long long k_min = (l + G -1) / G;
        long long k_max = r / G;
        
        if(k_max < k_min){
            cout << "-1 -1\n";
            continue;
        }
        
        if(k_min == k_max){
            if(k_min ==1){
                // A = G*1, B = G*1
                cout << G << " " << G << "\n";
            }
            else{
                cout << "-1 -1\n";
            }
            continue;
        }
        
        // Check if 1 is in [k_min, k_max]
        if(k_min <=1 && k_max >=1){
            // A = G*1, B = G*k_max
            cout << G << " " << G * k_max << "\n";
            continue;
        }
        
        // Else, check gcd(k_min, k_max)
        long long gcd_val = compute_gcd(k_min, k_max);
        if(gcd_val ==1){
            cout << G * k_min << " " << G * k_max << "\n";
            continue;
        }
        else{
            if(k_max -1 >=k_min){
                // Check gcd(k_max-1, k_max) ==1
                // Which is always true since consecutive integers are coprime
                cout << G * (k_max -1) << " " << G * k_max << "\n";
                continue;
            }
            else{
                // No valid pair
                cout << "-1 -1\n";
                continue;
            }
        }
    }
}
    