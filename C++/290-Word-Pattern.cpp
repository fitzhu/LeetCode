#include<string>
#include<unordered_map>
using namespace std;

// 用两个字典存mapping，char2word和word2char
// 然后判断一下pattern和words的长度是否相等
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        int i = 0, j = 0;
        for (const auto& p : pattern) {
            if (i >= str.length()) {
                return false;
            }
            j = str.find(" ", i);
            if (j == string::npos) {
                j = str.length();
            }
            const string w = str.substr(i, j - i);
            if (!w2p.count(w) && !p2w.count(p)) {
                // build mapping
                w2p[w] = p;
                p2w[p] = w;
            } else if (!w2p.count(w) || w2p[w] != p) {
                return false;
            }
            i = j + 1;
        }
        if (j < str.length()) {
            return false;
        }
        return true;
    }
};

int main() {
    string pattern{"jquert"};
    string str{"jquert"};
    Solution tmp;
    auto res = tmp.wordPattern(pattern, str);
}