/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        // int *freq=new int[26]();  not only small alphabets
        unordered_map<char,int> freq;
        int i=0,j=0,len=0;
        int n=s.size();
        while(i<n && j<n)
        {
            if(freq.find(s[j])==freq.end())
            {
                freq[s[j]]++;
                j++;
                len=max(len,j-i);
            }
            else
            {
                freq.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};
