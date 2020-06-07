/*Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1*/


class Solution {
public:
    int getSum(int a, int b) {
        if(abs(a)==abs(b) && a!=b)
            return 0;  //-2+2=0
        //adder concept
        int sum=a^b;
        unsigned int carry=a&b;
        if(carry==0)
            return sum;
        return getSum(sum,carry<<1);
    }
};
