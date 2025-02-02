#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int64_t binPow(int64_t x, int64_t n, int64_t MOD = 1E9 + 7) {
    assert(n >= 0);
    x %= MOD;
    int64_t res = 1;
    
    while (n > 0) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int numCases = 1;
    int stringLength, patternCount, patternLength;
    string pattern;
    cin >> stringLength >> patternCount >> pattern;

    string targetString(stringLength, '#');
    vector<int> patternStartIndices(patternCount);
    for (auto &index : patternStartIndices) {
        cin >> index;
        index--;
        targetString[index] = pattern[0];
    }

    patternLength = pattern.size();
    for (int i = 0; i < stringLength; i++) {
        if (targetString[i] != '#') {
            int patternIndex = 1;
            i++;
            while (i < stringLength && patternIndex < patternLength && targetString[i] == '#') {
                targetString[i] = pattern[patternIndex];
                i++;
                patternIndex++;
            }
            i--;
        }
    }

    int wildcardCount = count(targetString.begin(), targetString.end(), '#');    
    string concatenatedString = pattern + "$" + targetString;
    auto Z = z_function(concatenatedString);

    vector<int> validPositions;
    for (int i = 0; i < concatenatedString.size(); i++) {
        if (Z[i] == patternLength) {
            validPositions.push_back(i - 1 - patternLength);
        }
    }

    bool isValid = true;
    for (auto index : patternStartIndices) {
        if (!binary_search(validPositions.begin(), validPositions.end(), index)) {
            isValid = false;
            break;
        }
    }

    cout << (isValid ? binPow(26, wildcardCount) : 0) << "\n";
    return 0;
}