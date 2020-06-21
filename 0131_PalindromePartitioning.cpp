/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    bool isPalindrome(string s,int l,int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void helper(string str,int s,vector<string> &currList, vector<vector<string>> &ans)
    {
        // s- starting index of substring         
        // e- ending index of substring
        for(int e=s;e<str.size();e++)
        {
            if(isPalindrome(str,s,e))
            {
                currList.push_back(str.substr(s,e-s+1));
                
                if(e==str.size()-1)
                    ans.push_back(currList);
                else
                    helper(str,e+1,currList,ans);
                
                //backtrack
                currList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currList;
        helper(s,0,currList,ans);
        return ans;
    }
};
