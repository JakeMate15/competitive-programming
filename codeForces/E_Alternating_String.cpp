#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int minChangesForAlternating(const string& s, int n) {
    if (n % 2 == 1) {
        return min(minChangesForAlternating(s.substr(0, n - 1), n - 1) + 1,
                   minChangesForAlternating(s.substr(1), n - 1) + 1);
    }
    
    unordered_map<char, int> evenCount, oddCount;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            evenCount[s[i]]++;
        } else {
            oddCount[s[i]]++;
        }
    }
    
    int evenMax = 0, oddMax = 0;
    char evenMaxChar, oddMaxChar;
    
    for (const auto& p : evenCount) {
        if (p.second > evenMax) {
            evenMax = p.second;
            evenMaxChar = p.first;
        }
    }
    
    for (const auto& p : oddCount) {
        if (p.second > oddMax) {
            oddMax = p.second;
            oddMaxChar = p.first;
        }
    }
    
    int minChanges = n / 2 - evenMax + n / 2 - oddMax;
    
    if (evenMaxChar == oddMaxChar) {
        int evenSecondMax = 0, oddSecondMax = 0;
        
        for (const auto& p : evenCount) {
            if (p.first != evenMaxChar && p.second > evenSecondMax) {
                evenSecondMax = p.second;
            }
        }
        
        for (const auto& p : oddCount) {
            if (p.first != oddMaxChar && p.second > oddSecondMax) {
                oddSecondMax = p.second;
            }
        }
        
        minChanges = min(minChanges, n / 2 - evenSecondMax + n / 2 - oddMax);
        minChanges = min(minChanges, n / 2 - evenMax + n / 2 - oddSecondMax);
    }
    
    return minChanges;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << minChangesForAlternating(s, n) << endl;
    }
    
    return 0;
}
