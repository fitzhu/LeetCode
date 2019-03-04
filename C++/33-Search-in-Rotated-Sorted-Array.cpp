#include<vector>
using namespace std;

// 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[mid] >= nums[left] && nums[left] <= target && target <= nums[mid]) || 
                        (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};