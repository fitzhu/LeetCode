#include<string>
#include<unordered_map>
using namespace std;

// 只遍历一遍，hash_map记录当前字符最后出现的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Record the last occurrence of each char.
        unordered_map<char, size_t> last_occurrence;
        size_t starting_idx = 0, ans = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            auto it(last_occurrence.find(s[i]));
            if (it == last_occurrence.cend()) {
                last_occurrence.emplace_hint(it, s[i], i);
            } else {
                if (it->second >= starting_idx) {
                    ans = max(ans, i - starting_idx);
                    starting_idx = it->second + 1;
                }
                it->second = i;
            }
        }
        ans = max(ans, s.size() - starting_idx);
        return ans;
    }
};