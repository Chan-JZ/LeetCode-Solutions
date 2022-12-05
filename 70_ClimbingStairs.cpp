#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        std::vector<int> table(n+1);
        table[1] = 1;
        table[2] = 2;

        for (int i=3; i<=n; i++) {
            table[i] = table[i-1] + table[i-2];
        }

        return table[n];
    }
};