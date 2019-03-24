#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

// 全排列的规律：从数组倒着查找，找到nums[i]比nums[i+1]小的位置，
//               就将nums[i]跟nums[i+1]到nums[nums.length-1]当中找到一个最小的比nums[i]大的元素交换。
//               交换后，再把nums[i+1]到nums[nums.length-1]逆序
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        nextPermutation(nums.begin(), nums.end());
    }
private:
    template<typename BidiIt>
    void nextPermutation(BidiIt begin, BidiIt end) {
        const auto rbegin = reverse_iterator<BidiIt>(end);
        const auto rend = reverse_iterator<BidiIt>(begin);

        // Find the first element (pivot) which is less than its successor.
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot)) {
            ++pivot;
        }

        if (pivot != rend) {
            // find the number which is greater than pivot, and swap it with pivot
            auto change = find_if(rbegin, rend, bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        }
        // Make the sequence after pivot non-descending
        reverse(rbegin, pivot);

        return;
    }
};

int main() {
    vector<int> nums{1,2,3};
    Solution tmp;
    tmp.nextPermutation(nums);
}