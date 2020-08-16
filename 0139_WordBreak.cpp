/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool find(string t, vector<string>& wordDict)
    {
        for(int i=0;i<wordDict.size();i++)
        {
            if(wordDict[i]==t)
                return true;
        }
        return false;
    }
    
    bool helper(string s,int i, vector<string>& wordDict)
    {
        if(i>=s.size())
            return true;
        for(int j=1;j<=s.size()-i;j++)
        {
            string t= s.substr(i,j);
            if(find(t,wordDict))
            {
                if(helper(s,i+j,wordDict))
                    return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s,0,wordDict); 
    }
};
