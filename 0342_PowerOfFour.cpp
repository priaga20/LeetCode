/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true

Example 2:

Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?*/


class Solution {
public:
    float logn(int n,int r)
    {
        return log(n)/log(r);
    }

    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        return floor(logn(num,4))==ceil(logn(num,4));
    }
};