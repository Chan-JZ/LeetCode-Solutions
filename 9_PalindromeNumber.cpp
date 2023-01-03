#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long long num = x, num2 = 0;

        while (num) {
            num2 = (num2 * 10) + (num % 10);
            num /= 10;
            cout << "num2: " << num2 << endl;
        }

        return (num2 == x) && x >= 0;
    }
};