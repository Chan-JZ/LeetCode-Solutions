#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0)); 
        vector<int> elements;
        for (int i=1; i<=n*n; i++) elements.push_back(i);
        int x = 0, y = 0;
        int count = 0;
        int len = n-1;

        while (count < n*n) {
            if (len == 0) {
                result[x][y] = elements[count];
                break;
            }

            for (int i=0; i<len; i++) {
                result[x][y++] = elements[count++];
            }

            for (int i=0; i<len; i++) {
                result[x++][y] = elements[count++];
            }

            for (int i=0; i<len; i++) {
                result[x][y--] = elements[count++];
            }

            for (int i=0; i<len; i++) {
                result[x--][y] = elements[count++];
            }

            len -= 2;
            x++;
            y++;
        }

        return result;
    }
};

int main() {
    Solution *s1 = new Solution();
    vector<vector<int>> v = s1->generateMatrix(5);

    for (vector<int> x : v) {
        for (int y : x) cout << y << " ";
        cout << endl;
    }
}