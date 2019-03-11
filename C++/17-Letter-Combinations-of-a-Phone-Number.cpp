#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
    典型的广度优先搜索
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};
        helper(res, "", digits, table, 0);
        return res;
    }
private:
    void helper(vector<string>& res, string now, const string& digits, unordered_map<char, string>& table, int k) {
        if (now.size() == digits.size()) {
            res.push_back(now);
            return;
        }

        const auto& tmp = table[digits[k]];
        for (auto s : tmp) {
            now += s;
            helper(res, now, digits, table, k + 1);
            now.pop_back();
        }
    }
};