#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        for (int i = 0; i < res.size(); ++i) {
            int prev = res[0] = 1;
            for (int j = 1; j <= i; ++j) {
                int tmp = res[j];
                res[j] += prev;
                prev = tmp;
            }
        }
        return res;
    }
};