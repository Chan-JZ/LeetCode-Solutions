#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int ret = 0;
        int xy = 0, yx = 0;
        int len = s1.length();

        for (int i=0; i<len; i++) {
            if (s1[i] == 'x' && s2[i] == 'y') xy++;
            if (s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        ret += xy/2;
        xy = (xy % 2) ? 1 : 0;

        ret += yx/2;
        yx = (yx % 2) ? 1 : 0;

        if (!xy && ! yx) return ret;
        if (xy && yx) return ret+2;
        return -1;
    }
};