#include<string>
#include<vector>
using namespace std;

// 不能用hash表，它是一个pair
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> s2t(256, 0), t2s(256, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i]) {
                // Contradict mapping.
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s{"ab"}, t{"add"};
    Solution tmp;
    auto res = tmp.isIsomorphic(s, t);
}