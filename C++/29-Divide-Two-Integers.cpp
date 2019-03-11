#include<algorithm>
#include<limits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if ((dividend == numeric_limits<int>::min()) && (divisor == -1)) {
            return numeric_limits<int>::max();
        }
        if (divisor == numeric_limits<int>::min()) {
            return dividend == numeric_limits<int>::min() ? 1 : 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            return -dividend;
        }

        int res = 0, i = 0, flag = 0;
        if (dividend == numeric_limits<int>::min()) {
            dividend += 1;
            flag = 1;
        }
        unsigned int p = abs(dividend), q = abs(divisor);
        while ((q << i) <= p) {
            i += 1;
        }
        for (int j = i - 1; j >= 0; --j) {
            if ((q << j) <= p) {
                p -= (q << j);
                res += (1 << j);
            }
        }
        // 处理溢出的情况
        if (flag == 1 && p + 1 == q) {
            res += 1;
        }
        if ((dividend ^ divisor) < 0) {
            res = -res;
        }
        return min(res, (1 << 31) - 1);
    }
};

/*
    只使用位运算进行加减乘除。数字在计算机中以补码的形式存在的，补码的优势：
        1. 符号位和数值部分一起运算，这样无需单独考虑符号;
        2. 把减法运算转化为加法运算来处理。
    Reference:
        https://blog.csdn.net/ojshilu/article/details/11179911
    注意：
        以下代码仅为参考思路，均没有考虑数值溢出的问题
*/

/*
    加法：可以看成是'和'与'进位'两部分，'和'的结果留在当前位, '进位'的结果加入到下一位
        1. 位的异或运算跟求'和'的结果一致:
            异或: 1^1=0 1^0=1 0^0=0
            求和: 1+1=0 1+0=1 0+0=0
        2. 位的与运算跟求'进位'的结果一致：
            位与: 1&1=1 1&0=0 0&0=0
            进位: 1+1=1 1+0=0 0+0=0
*/
int add(int a, int b) {
    if (b == 0) {
        return a;
    }
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}

/*
    减法：减法其实是用加法来实现的。求a - b时，其实是求a + (-b)。
        1. 这些都是以补码形式存储的。所以先需要求补码b的负；
        2. 补码b的负 = 全部位取反再加一
*/
int negtive(int i) {
    return add(~i, 1);
}
int subtraction(int a, int b) {
    return add(a, negtive(b));
}

/*
    乘法：需要单独考虑符号位
        第一种思路：利用循环加法代替乘法。把a累加b次，O(n)
        第二种思路：二进制上做乘法。和十进制乘法规则一致，将被乘数错位加在积上。O(logn)
*/
// 先引入两个工具函数：
//      getsign(): 取一个数的符号，看它是正还是负
//      bepositive(): 将一个数变为正数。如果本来就是正，则不变；如果是负，则变为相反数。
int getsign(int i) {
    return (i >> 31);
}
// 注意对于-2147483648，求负会溢出。
int bepositive(int i) {
    if (getsign(i)) {
        return negtive(i);
    } else {
        return i;
    }
}

// 第一种思路：利用循环加法代替乘法。把a累加b次，O(n)
int multiply1(int a, int b) {
    bool flag = true;
    if (getsign(a) == getsign(b)) {
        flag == false;
    }

    a = bepositive(a);
    b = bepositive(b);
    int ans = 0;
    while (b) {
        ans = add(ans, a);
        b = subtraction(b, 1);
    }
    if (flag) {
        ans = negtive(ans);
    }
    return ans;
}

// 第二种思路：在二进制上做乘法，与十进制乘法一致。将被乘数错位地加在积上。O(logn)
int multiply(int a, int b) {
    bool flag = true;
    if (getsign(a) == getsign(b)) {
        flag == false;
    }

    a = bepositive(a);
    b = bepositive(b);
    int ans = 0;
    while (b) {
        if (b & 1) {
            ans = add(ans, a);
        }
        a = a << 1; // 把a错位加在积上
        b = b >> 1; // 从最低位开始依次判断b的每一位
    }
    if (flag) {
        ans = negtive(ans);
    }
    return ans;
}

/*
    除法：和乘法一样，也是可以有两种思路
        第一种思路：循环被除数减除数，看能减多少次之后变得不够减。O(n)
        第二种思路：上一种减得太慢了，采用类似二分法得思路，从除数*最大倍数开始测试：
            如果比被除数小，则要减去。
            下一回让除数的倍数减少为上一次倍数的一半，这样的直到倍数为1时，
            就能把被除数中所有的除数减去，并得到商。O(logn)
*/

// 第一种思路：循环被除数减除数

int division(int a, int b) {
	if (b == 0) {
        return 0;
    }

	bool flag = true;
	if (getsign(a) == getsign(b)) { //积的符号判定
        flag = false;
    }

	a = bepositive(a);
	b = bepositive(b);
 
	int n = 0;
	a = subtraction(a, b);
	while (a >= 0) {
		n = add(n, 1);
		a = subtraction(a, b);
	}
 
	if (flag) {
        n = negtive(n);
    }
	return n;
}

// 第二种解法：
int divide(int dividend, int divisor) {
	bool flag = true;
	if (getsign(dividend) == getsign(divisor)) { //积的符号判定 
        flag = false;
    }

	unsigned int x = bepositive(dividend);
	unsigned int y = bepositive(divisor);
 
    int ans=0;
	int i=31;
    while (i >= 0) {  
        //比较x是否大于y*(1<<i)=(y<<i)，避免直接比较，因为不确定y*(1<<i)是否溢出  
        if( (x>>i) >= y) { //如果够减
            ans = add(ans, (1 << i)); 
            x = subtraction(x, (y << i));
        }
		i = subtraction(i, 1);
    } 
	if(flag) {
        ans = negtive(ans);
    }
    return ans;
}