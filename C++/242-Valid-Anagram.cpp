#include<string>
#include<unordered_map>
using namespace std;

// 把两个string依次遍历，第一个存在hash里面，第二个再依次去找
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> count;
        for (auto c : s) {
            ++count[tolower(c)];
        }
        for (auto c : t) {
            --count[tolower(c)];
            if (count[tolower(c)] < 0) {
                return false;
            }
        }
        return true;
    }
};