/*Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.

Note:

    Both dividend and divisor will be 32-bit signed integers.
    The divisor will never be 0.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        //possible overflow case
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        // if(dividend==INT_MAX && divisor==1)
        //     return INT_MAX;
        
        int sign=0;
        if((dividend>0) ^ (divisor>0))
            sign=-1;
        else
            sign=1;
        
        long divd=abs(dividend);
        long divs=abs(divisor);
        
        long ans=0;
        while(divd >= divs)
        {
            long temp=divs,quotient=1;
            while((temp<<1) <= divd)
            {
                temp=temp<<1;
                quotient=quotient<<1;
            }
            ans+=quotient;
            divd=divd-temp;
        }
        return sign*ans;
    }
};
