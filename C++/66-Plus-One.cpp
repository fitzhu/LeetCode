#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it == 9) {
                *it = 0;
            } else {
                *it += 1;
                return digits;
            }
        }
        digits[0] = 1;
        digits.emplace_back(0);
        return digits;
    }
};