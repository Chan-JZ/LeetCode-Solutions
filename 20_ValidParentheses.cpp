#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        stack<char> stk;

        for (char c : s) {
            if (c == '(') stk.push(')');
            else if (c == '{') stk.push('}');
            else if (c == '[') stk.push(']');
            else if (stk.empty() || stk.top() != c) return false;
            else stk.pop();
        }

        return stk.empty();
    }
};