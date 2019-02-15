#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for (auto it = s.crbegin(); it != s.crend(); ++it) {
            if (*it == ' ') {
                if (len > 0) {
                    break;
                }
            } else {
                ++len;
            }
        }
        return len;
    }
};

int main() {
    string s("hello world");
    Solution tmp;
    auto ret = tmp.lengthOfLastWord(s);
}