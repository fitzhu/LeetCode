#include<vector>
#include<algorithm>
using namespace std;

// 使用前后两个指针l和r，遍历每一种宽度得到的最大矩形区域面积。
// 我们只会将较短的一边往里移动，因为只有这样才可能得到更大面积的矩形。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return max_area;
    }
};