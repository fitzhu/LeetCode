#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> tmp;
        for (size_t i = 0; i < nums.size(); ++i) {
            auto it = tmp.find(nums[i]);
            if (it == tmp.cend()) {
                tmp.emplace(target - nums[i], i);
            } else {
                return {it->second, i};
            }
        }
        return {};
    }
};