#include<string>
using namespace std;

// 26进制数
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int dvd{n};

        while (dvd) {
            res.push_back((dvd - 1) % 26 + 'A');
            dvd = (dvd - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};