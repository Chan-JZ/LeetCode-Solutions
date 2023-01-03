#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.length();
        int numMidElements = numRows - 2;
        int width =  ceil((float)((float)n / ((float)numRows + (float)numMidElements))) * (numMidElements+1);

        vector<vector<char>> grid(numRows, vector<char>(width, '!'));
        int count = 0;
        int curCol = 0;
        int curRow = numRows - 2;

        while (count < n) {
            for (int i=0; i<numRows; i++) {
                if (count >= n) break;
                grid[i][curCol] = s[count++];
            }
            curCol++;

            for (int i=0; i<numMidElements; i++) {
                if (count >= n) break;
                grid[curRow--][curCol++] = s[count++];
            }
            curRow = numRows - 2;
        }

        string ret = "";
        for (vector<char> a : grid) {
            for (char b : a) {
                if (b != '!') ret += b;
            }
        }

        return ret;
    }
};
*/


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ret;
        int n = s.length();
        int curIndex = 0;
        int charMid = numRows - 2;
        int charInBetween = numRows + charMid;

        for (int curRow = 0; curRow < numRows; curRow++) {
            curIndex = curRow;
            if (curIndex < n) ret += s[curIndex];
            
            while (curIndex < n) {
                curIndex += charInBetween;
                int inBetweenIndex;
                if (curRow != 0 && curRow != numRows - 1) {
                    inBetweenIndex = curIndex - curRow * 2;
                    if (inBetweenIndex < n) ret += s[inBetweenIndex];
                }
                if (curIndex < n) ret += s[curIndex];
            }
        }

        return ret;
    }
};


int main() {
    Solution *s1 = new Solution();
    s1->convert("PAYPALISHIRING", 3);
}