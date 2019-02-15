#include<string>
#include<limits>
using namespace std;

// 直接遍历处理，注意一些它的限制条件
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }

        int ans = 0, sign = 1, i = 0;
        // skip whitespace
        while (str[i] == ' ' || str[i] == '\t') {
            ++i;
        }
        if (i == str.length()) {
            return 0;
        }
        // parse sign
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        // compute integer
        for (; i < str.length() && isdigit(str[i]); ++i) {
            if (ans > (numeric_limits<int>::max() - (str[i] - '0')) / 10) {
                return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            ans *= 10;
            ans += str[i] - '0';
        }
        ans *= sign;
        return ans;
    }
};