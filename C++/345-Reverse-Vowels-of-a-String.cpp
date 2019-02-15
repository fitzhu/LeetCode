#include<string>
using namespace std;

// 一样是前后两个指针找到第一个符合条件的位置，然后交换。注意下前指针的位置一定要小于后指针
class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (!is_vowel(tolower(s[i]))) {
                ++i;
            } else if (!is_vowel(tolower(s[j]))) {
                --j;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
private:
    const string vowels_ = "aeiou";
    bool is_vowel(char a){
        return vowels_.find(a) != string::npos;
    }
};

int main() {
    string s{"hello"};
    Solution tmp;
    auto res = tmp.reverseVowels(s);
}