#include<string>
using namespace std;
// 直接遍历求成对的字符，使用取反操作使成对之后的字符计数清零
class Solution {
public:
    int longestPalindrome(string s) {
        char twice[128] = {0};
        int length = 0;
        for (auto c : s) {
            twice[c] = !twice[c];
            if (!twice[c]) {
                length += 2;
            }
        }
        return length < s.size() ? length + 1 : length;
    }
};

int main() {
    string s{"abccccdd"};
    Solution tmp;
    auto res = tmp.longestPalindrome(s);
}