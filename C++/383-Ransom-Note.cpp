#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> lookup;
        for (const auto& i : magazine) {
            ++lookup[i];
        }
        for (const auto& i : ransomNote) {
            if (lookup[i] > 0) {
                --lookup[i];
            } else {
                return false;
            }
        }
        return true;
    }
};