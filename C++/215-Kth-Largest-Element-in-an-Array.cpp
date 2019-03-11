#include<vector>
#include<random>
using namespace std;

// 类似快排的思想：随机选取一个基准数，将比基准数大的数全部交换到它前面的位置去。若基准数的位置正好为k-1时，则返回。
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        default_random_engine gen((random_device())());
        while (left <= right) {
            // generate a random int in [left, right]
            uniform_int_distribution<int> dis(left, right);
            int idx = dis(gen);
            int new_idx = qsort(nums, left, right, idx);
            if (new_idx == k - 1) {
                return nums[new_idx];
            } else if (new_idx > k - 1) {
                right = new_idx - 1;
            } else {
                left = new_idx + 1;
            }
        }
        return -1;
    }
private:
    int qsort(vector<int>& nums, int left, int right, int idx) {
        int value = nums[idx];
        int new_idx = left;
        swap(nums[idx], nums[right]);
        for (int i = left; i < right; ++i) {
            if (nums[i] > value) {
                swap(nums[i], nums[new_idx++]);
            }
        }
        swap(nums[right], nums[new_idx]);
        return new_idx;
    }
};

int main() {
    Solution tmp;
    vector<int> nums({3,2,1,5,6,4});
    auto res = tmp.findKthLargest(nums, 2);
    return 1;
}