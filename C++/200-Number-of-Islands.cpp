#include<vector>
using namespace std;

// 深度优先搜索，从找到第一个1开始向四周搜索，递归直到四周全都为0为止，且遍历过的位置置0
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) {
            return 0;
        }
        n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
private:
    int n, m;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
        }
    }
};