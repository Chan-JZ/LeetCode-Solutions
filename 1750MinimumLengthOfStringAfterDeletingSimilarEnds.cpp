#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();
        int ret = len, head = 0, tail = len - 1;

        while (s[head] == s[tail] && head < tail) {
            while (head < len && head+1 < tail && s[head+1] == s[head]) head++, ret--;

            while (tail > 0 && head < tail-1 && s[tail-1] == s[tail]) tail--, ret--;

            head++, tail--, ret -= 2;
        }

        return ret;
    }
};

class Solution {
public:
    int minimumLength(string s) {
        int head = 0, tail = s.length() - 1;

        while (s[head] == s[tail] && head < tail) {
            while (head+1 < tail && s[head+1] == s[head]) head++;

            while (head < tail-1 && s[tail-1] == s[tail]) tail--;

            head++, tail--;
        }

        return tail - head + 1;
    }
};