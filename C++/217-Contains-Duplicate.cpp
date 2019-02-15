#include<vector>
#include<unordered_set>
using namespace std;

// 直接用一个hash存，然后再比对size
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};