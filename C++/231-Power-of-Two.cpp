// 位操作：2的幂次方的数，二进制编码只有一个1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        if ((n & n - 1) == 0) {
            return true;
        }
        return false;
    }
};