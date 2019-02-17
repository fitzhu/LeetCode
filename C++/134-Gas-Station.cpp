#include<vector>
using namespace std;

// 一次遍历，用一个标志位run记录当前剩余油量，如果run<0，则起点为下一点，run重新置零
// 同时用另一标志位rest记录总体的剩余油量，如果跑完一圈rest<0，则不能行驶一圈
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0, run = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            run += gas[i] - cost[i];
            rest += gas[i] - cost[i];
            if (run < 0) {
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1 : start;
    }
};