#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string s : tokens) {
            if (isdigit(s[0]) || (s[0] == '-' && s.length() > 1)) {
                if (s[0] == '-') {
                    string temp = s.erase(0, 1);
                    int toPush = stoi(temp) * -1;
                    cout << "topush: " << toPush << endl;
                    stk.push(toPush);
                }
                else stk.push(stoi(s));
                cout << "pushed " << stk.top() << " to stack" << endl;
            } else {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();

                if (s == "+") stk.push(x + y);
                if (s == "-") stk.push(y - x);
                if (s == "*") stk.push(x * y);
                if (s == "/") stk.push(y / x);

                cout << "new stack top: " << stk.top() << endl;
            }
        }

        return stk.top();
    }
};