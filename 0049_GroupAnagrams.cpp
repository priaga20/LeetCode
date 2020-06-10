/*Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter. */

class Solution {
public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        if(strs.size()==0)
            return ans;
        
        unordered_map<string,vector<string> > m;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(m.find(temp)!=m.end())
            {
                m[temp].push_back(strs[i]);
                continue;
            }
            else
            {
                m[temp]=vector<string>{strs[i]};
            }
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};