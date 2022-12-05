#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
       string result = "";
       int i = a.length()-1, j = b.length()-1;
       int carry = 0, sum = 0;

       while(i >= 0 || j >= 0) {
           sum = (i >= 0 ? (a[i] - '0') : 0) + (j >= 0 ? (b[j] - '0') : 0) + carry;
           carry = sum/2;
           result = to_string(sum%2) + result;
           i--;  
           j--;
       }

       if (carry == 1) result = to_string(1) + result;

       return result;
    }
};