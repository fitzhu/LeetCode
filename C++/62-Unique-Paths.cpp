#include<vector>
using namespace std;

// 动态规划：到达当前位置的路径数目，等于它到达它上面位置的路径数加到达它左边位置的路径数
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    tmp[i][j] = 1;
                } else {
                    tmp[i][j] = tmp[i - 1][j] + tmp[i][j - 1];
                }
            }
        }
        return tmp[m - 1][n - 1];
    }
};