#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret;
        int dif = INT32_MAX;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            int left = i + 1;
            int right = n - 1;

            bool flag = true;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) return sum;

                if (abs(sum - target) < dif) {
                    dif = abs(sum - target);
                    ret = sum;
                }
                if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ret;
    }
};