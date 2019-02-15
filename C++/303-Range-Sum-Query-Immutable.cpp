#include<vector>
using namespace std;

// 数组不可变的话，可以用积分图的方式达到常数时间求区域和
class NumArray {
public:
    NumArray(vector<int> nums) {
        accu.emplace_back(0);
        for (const auto& num : nums) {
            accu.emplace_back(accu.back() + num);
        }
    }
    
    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};