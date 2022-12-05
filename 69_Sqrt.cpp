#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;

        int ret = 0;
        int start = 1, end = x/2;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (x / mid == mid) return mid;
            else if (x / mid > mid) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return start-1;
    }
};