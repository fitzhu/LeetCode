#include<algorithm>
#include<limits>
using namespace std;

// 常数时间判断是否为3的幂，直接由更大的3的幂的数和它取余
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && max_pow3 % n == 0;
    }
private:
    static const int max_log3 = log(numeric_limits<int>::max()) / log(3);
    static const int max_pow3 = pow(3, max_log3);
};