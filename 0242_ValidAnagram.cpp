/*Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size())
            return false;
        int *arr=new int[26]();
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)
                return false;
        }
        return true;
    }
};