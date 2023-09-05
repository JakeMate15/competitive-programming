#include<bits/stdc++.h>
using namespace std;

std::string getKeyWithMaxValue(const std::map<std::string, int>& inputMap) {
    std::string maxKey;
    int maxValue = std::numeric_limits<int>::min(); // Valor mínimo posible de un int

    for (const auto& pair : inputMap) {
        if (pair.second > maxValue) {
            maxValue = pair.second;
            maxKey = pair.first;
        }
    }

    return maxKey;
}

int main() {
    int t = 100080;
    map<string,long long> resultados;

    while(t--){
        int n = 100;

        random_device rd;
        mt19937 gen(rd());

        int lowerBound = 1;
        int upperBound = 2;

        uniform_int_distribution<int> distribution(lowerBound, upperBound);

        map<string,int> mp;
        vector<string> nom = {"j","d"};

        for (int i = 0; i < n; ++i) {
            int randomNumber = distribution(gen);
            mp[nom[randomNumber-1]]++;
        }

        string jeje = getKeyWithMaxValue(mp);
        resultados[jeje]++;
    }

    for(auto &[x,y]: resultados){
        cout << x << " " << y << endl;
    }

    return 0;
}
