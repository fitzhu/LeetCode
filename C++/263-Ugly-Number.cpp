
// 丑数为质因数只有2,3,5的数，也就是说把该数直接往后除就行了
class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) {
            return false;
        }
        for (const auto& i : {2, 3, 5}) {
            while (num % i == 0) {
                num /= i;
            }
        }
        return num == 1;
    }
};