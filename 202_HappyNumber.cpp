#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        bool isHappy = false;
        set<int> uniqueSum;

        while (true) {
            string curNum = to_string(n);
            int curSum = 0;

            for (int i=0; i<curNum.length(); i++) {
                curSum += pow((curNum[i] - '0'), 2);
            }
            cout << curSum << endl;
            if (uniqueSum.find(curSum) != uniqueSum.end()) break;
            else {
                if (curSum == 1) return true;
                uniqueSum.insert(curSum);
                n = curSum;
            }
        }

        return isHappy;
    }
};