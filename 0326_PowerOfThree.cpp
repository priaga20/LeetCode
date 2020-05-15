/*Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true

Example 2:

Input: 0
Output: false

Example 3:

Input: 9
Output: true

Example 4:

Input: 45
Output: false*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        //O(log n to base 3)
        if(n<1)
            return false;
        while(n%3==0)
        {
            n/=3;
        }
        if(n==1)
            return true;
        else
            return false;
    }
};