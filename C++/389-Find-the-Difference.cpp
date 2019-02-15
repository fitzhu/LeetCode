#include<string>
#include<functional>
using namespace std;

// 找单独存在的数，直接按位异或
class Solution {
public:
    char findTheDifference(string s, string t) {
        return accumulate(s.cbegin(), s.cend(), 0, bit_xor<int>()) ^
                accumulate(t.cbegin(), t.cend(), 0, bit_xor<int>());
    }
};