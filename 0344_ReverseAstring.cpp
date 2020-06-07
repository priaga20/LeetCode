/*Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place 
with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]*/

//an in-place algorithm is an algorithm which transforms input using no auxiliary data structure.

class Solution {
public:
     void reverseString(vector<char>& s){
        int l=0,r=s.size()-1;
        while(l<r)
        {
            char t=s[l];
            s[l]=s[r];
            s[r]=t;
            l++;
            r--;
        }
    }
};