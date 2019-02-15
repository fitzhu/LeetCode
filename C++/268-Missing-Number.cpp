#include<vector>
using namespace std;

// 求单独存在的数，可以考虑用异或操作
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num ^= nums[i] ^(i + 1);
        }
        return num;
    }
};