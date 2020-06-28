/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        //O(n^2) - time
        //O(1) - space
        if(s.size()==0 || s.size()==1)
            return s;
        //start var point to the starting index of longest palindrome
        int maxLen=1,start=0,len=s.size();
        int left,right;  //will expand around centre
        for(int i=1;i<len;i++)
        {
            //considering even length palindrome having i as one of the centres
            left=i-1;
            right=i;
            while(left>=0 && right<len && s[left]==s[right])
            {
                if(right-left+1 > maxLen)
                {
                    maxLen=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
            //considering odd length palindrome having i as the centre
            left=i-1;
            right=i+1;
            while(left>=0 && right<len && s[left]==s[right])
            {
                if(right-left+1 > maxLen)
                {
                    maxLen=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxLen);
    }
};
