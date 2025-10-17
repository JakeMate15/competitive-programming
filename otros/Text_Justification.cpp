#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "/algoDebug.h"
#else
    #define debug(x...)
    #define RAYA 
    #define raya 
#endif

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        auto getLine = [&] (vector<string> WORDS, int totalLength, bool finalLine) -> string {
            int totalSpaces = max((int) WORDS.size() - 1, 1);
            int spaceWidth = (maxWidth - totalLength) / totalSpaces;
            int extraSpace = (maxWidth - totalLength) % totalSpaces;

            string newLine = "";
            for (int i = 0; i < WORDS.size(); i++) {
                newLine += WORDS[i];
                if (finalLine) {
                    newLine += " ";
                } else if (i < WORDS.size() - 1) {
                    newLine += string(spaceWidth, ' ');
                }
                if (i == 0 && !finalLine) {
                    newLine += string(extraSpace, ' ');
                }
            }

            return newLine;
        };

        int wordsLength = 0, spaces = 0;
        vector<string> currentLine, text;
        for (int i = 0; i < words.size(); i++) {
            int newLength = wordsLength + spaces + words[i].size() + (currentLine.size() > 0);
            
            if (newLength <= maxWidth) {
                spaces += currentLine.size() > 0;
                currentLine.push_back(words[i]);
                wordsLength += words[i].size();
            } else {
                text.push_back(getLine(currentLine, wordsLength, false));
                currentLine.clear();
                currentLine.push_back(words[i]);
                wordsLength = words[i].size();
                spaces = 0;
            }
        }

        if (currentLine.size() > 0) {
            text.push_back(getLine(currentLine, wordsLength, true));
        }

        return text;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int mx;
    cin >> mx;

    string s;
    vector<string> ss;
    while (cin >> s) {
        ss.push_back(s);
    }

    Solution sol;
    auto txt = sol.fullJustify(ss, mx);
    for (auto x: txt) {
        cout << x << "\n";
    }

    return 0;
}

