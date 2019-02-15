#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }
        
        unordered_set<int> lookup{nums1.cbegin(), nums1.cend()};
        vector<int> res;
        for (const auto& i : nums2) {
            if (lookup.count(i)) {
                res.emplace_back(i);
                lookup.erase(i);
            }
        }
        return res;
    }
};