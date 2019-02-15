// 计算有几个5的因数
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n >= 1) {
            n /= 5;
            res += n;
        }
        return res;
    }
};