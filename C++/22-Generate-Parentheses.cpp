#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generator(res, "", 0, 0, n);
        return res;
    }
private:
    void generator(vector<string>& res, string s, int l, int r, int n) {
        if (l == n) {
            res.emplace_back(s.append(n - r, ')'));
            return;
        }
        generator(res, s + "(", l + 1, r, n);
        if (l > r) {
            generator(res, s + ")", l, r + 1, n);
        }
    }
    // l记录“(”的个数，r记录“)”的个数
    void generator2(vector<string>& res, string s, int l, int r, int n) {
        if (l > n || r > n){
            return;
        }
        if (l == n && r == n) {
            res.emplace_back(s);
            return;
        }
        generator2(res, s + "(", l + 1, r, n);
        if (l > r) {
            generator2(res, s + ")", l, r + 1, n);
        }
    }
};
