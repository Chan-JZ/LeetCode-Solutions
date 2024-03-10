#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret;

        for (int x : nums) m[x]++;

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > nums.size()/2) ret = it->first;
        }

        return ret;
    }
};