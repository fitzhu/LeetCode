#include<unordered_set>
using namespace std;

// 用一个hash存遍历过的数，如果出现了重复的数则返回false，如果出现了1则返回true
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1 && !visited.count(n)) {
            visited.emplace(n);
            n = nextNumber(n);
        }
        return n == 1;
    }
private:
    int nextNumber(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};