#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s){
        unordered_map<char, int> roman_map = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int num = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
                num -= roman_map[s[i]];
            } else {
                num += roman_map[s[i]];
            }
        }
        return num;
    }
};

int main() {
    class Solution test;
    string str("IV");
    int num = test.romanToInt(str);
    cout << "The result is " << num << endl;
}