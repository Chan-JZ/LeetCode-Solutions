#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int globalMax = INT32_MIN;

        while (start < end) {
            int curHeight = min(height[start], height[end]);
            globalMax = max(globalMax, curHeight*(end - start));

            while(height[start] <= curHeight && start < end) start++;
            while(height[end] <= curHeight && start < end) end--;
        }

        return globalMax;
    }
};