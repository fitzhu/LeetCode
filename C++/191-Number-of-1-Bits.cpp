//技巧：直接去掉二进制中位置最靠后的1
//可以分情况讨论n末尾是1还是0来验证这个算法
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for ( ; n; n &= n - 1) {
            ++count;
        }
        return count;
    }
};