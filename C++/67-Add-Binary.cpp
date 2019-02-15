#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;

        for (auto a_it = a.rbegin(), b_it = b.rbegin(); a_it != a.rend() || b_it != b.rend();) {
            const int a_bit_i = (a_it != a.rend()) ? *a_it - '0' : 0;
            const int b_bit_i = (b_it != b.rend()) ? *b_it - '0' : 0;
            int sum = a_bit_i + b_bit_i + carry;
            carry = sum / 2;
            sum %= 2;
            res.push_back('0' + sum);

            if (a_it != a.rend()) {
                ++a_it;
            }
            if (b_it != b.rend()) {
                ++b_it;
            }
        }
        if (carry) {
            res.push_back('0' + carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};