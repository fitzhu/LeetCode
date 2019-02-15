#include<vector>
using namespace std;

// 对分查找，最小的数一定在无序的部分，每次判断mid右边的部分是否有序，然后来不断的缩小边界进行判断。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // find min left s.t. nums[left] < nums[left']
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};