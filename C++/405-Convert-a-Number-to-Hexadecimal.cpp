#include<string>
using namespace std;
/*
【笔记】核心思想，使用位运算，每4位，对应1位16进制数字。

    使用0xf(00...01111b)获取num的低4位。
    >>算数位移，其中正数右移左边补0，负数右移左边补1。
    位移运算并不能保证num==0，需要使用32位int保证（对应16进制小于等于8位
*/
class Solution {
public:
    string toHex(int num) {
        if (!num) {
            return "0";
        }

        string res;
        while (num && res.length() != sizeof(int) * 2) {
            int hex = num & 0xF;
            if (hex < 10) {
                res.push_back('0' + hex);
            } else {
                res.push_back('a' + hex - 10);
            }
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
