#include <iostream>
#include <vector>
#include <utility>

using namespace std;

\
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> m = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000},
        };

        string ret;
        while (num > 0) {
            for (auto it = m.rbegin(); it != m.rend(); ++it) {
                int curFrequency = num / it->second;
                cout << "curF" << curFrequency << ", " << it->second << endl;
                for (int i=0; i<curFrequency; i++) {
                    ret += it->first;
                    num -= it->second;
                }
            }
        }

        return ret;
    }
};