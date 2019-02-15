int guess(int num);
// 对分查找法
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};