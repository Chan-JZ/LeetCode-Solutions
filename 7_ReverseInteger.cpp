#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;

        while(x != 0) {
            int curInt = x % 10;
            x /= 10;

            if (ret > INT32_MAX / 10 || ret == INT32_MAX / 10 && curInt > 8) return 0;
            if (ret < -INT32_MAX / 10 || ret == -INT32_MAX / 10 && curInt > 7) return 0;

            ret = ret * 10 + curInt;
        }

        return ret;
    }
};
