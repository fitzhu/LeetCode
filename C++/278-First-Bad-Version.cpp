
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
// 这相当于在排序数值中查找数，用对分查找
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};