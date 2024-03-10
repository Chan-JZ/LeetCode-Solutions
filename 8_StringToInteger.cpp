#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;

        while(s[0] == ' ') s.erase(0, 1);
        if (s[0] == '-') {
            sign = -1;
            s.erase(0, 1);
        }
        else if (s[0] == '+') s.erase(0, 1);

        for (int i=0; i<s.length(); i++) {
            if (!isdigit(s[i])) break;

            int curDigit = (s[i] - '0');
            if (sign == 1) {
                if (result == INT32_MAX/10 && curDigit > 7) return INT32_MAX;
                else if (result > INT32_MAX/10) return INT32_MAX;
            }

            else {
                if (result == INT32_MIN/10 && curDigit > 8) return INT32_MIN;
                else if (result < INT32_MIN/10) return INT32_MIN;
            }
            
            if (sign == -1) {
                cout << "digit: " << curDigit << endl;
                result = (result * 10) - curDigit;
                cout << "result: " << result << endl;
            } else {
                result = (result * 10) + curDigit;
            }
            
        }

        return result;
    }
};

int main() {
    Solution *s1 = new Solution();
    cout << s1->myAtoi(" -42") << endl;
}