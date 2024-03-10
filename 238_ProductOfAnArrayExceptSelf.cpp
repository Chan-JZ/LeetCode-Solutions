#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        unordered_map<int, int> prefix;
        unordered_map<int, int> postfix;

        int curPrefix = 1;
        for (int i=0; i<nums.size(); i++) {
            ret[i] = curPrefix;
            curPrefix *= nums[i];
        }

        int curPostfix = 1;
        for (int i=nums.size()-1; i>=0; i--) {
            ret[i] *= curPostfix;
            curPostfix *= nums[i];
        }

        return ret;
    }
};