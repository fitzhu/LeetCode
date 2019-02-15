/*
理论上数字4幂的二进制类似于100，10000，1000000，etc...形式。可以有如下结论：
    4的幂一定是2的。
    4的幂和2的幂一样，只会出现一位1。但是，4的1总是出现在奇数位。
    0x5 = 0101b可以用来校验奇数位上的1。
*/
class Solution {
public:
    //0x5 = 0101b
    bool isPowerOfFour(int num) {
        if (num < 0 || num & (num - 1)) {//check(is or not) a power of 2.
            return false;
        }
        return num & 0x55555555;//check 1 on odd bits
    }
};