#include<vector>
#include<unordered_map>
using namespace std;

// 遍历vector，直接用hash map存每个数的位置
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_dict;
        for (int i = 0; i < nums.size(); ++i) {
            if ((num_dict.find(nums[i]) != num_dict.end()) & (i - num_dict[nums[i]] <= k)) {
                return true;
            } else {
                num_dict[nums[i]] = i;
            }
        }
        return false;
    }
};