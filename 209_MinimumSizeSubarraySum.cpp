#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int left = 0;
        int sum = 0;

        for (int right=0; right<nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                result = (right-left+1 < result) ? right-left+1 : result;
                sum -= nums[left++];
            }
        }

        return (result == INT32_MAX) ? 0 : result;
    }
};