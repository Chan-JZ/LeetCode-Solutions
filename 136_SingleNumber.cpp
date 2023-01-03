#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret;

        for (int x : nums) m[x]++;

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second %2 != 0) ret = it->first;
        }

        return ret;
    }
};