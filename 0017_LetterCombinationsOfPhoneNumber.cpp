/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does 
not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    string getString(char d)
    {
        if(d=='2') return "abc";
        if(d=='3') return "def";
        if(d=='4') return "ghi";
        if(d=='5') return "jkl";
        if(d=='6') return "mno";
        if(d=='7') return "pqrs";
        if(d=='8') return "tuv";
        if(d=='9') return "wxyz";
        return "";
    }
    
    vector<string> getCombinations(string digits,int s,vector<string> output)
    {
        //base case
        if(s==digits.size())  
        {
            output.push_back("");
            return output;
        }
        //hypothesis
        vector<string> smallOutput=getCombinations(digits,s+1,output);
        //small calculation
        string c=getString(digits[s]);
        for(int i=0;i<c.size();i++)
        {
            for(int j=0;j<smallOutput.size();j++)
            {
                output.push_back(c[i]+smallOutput[j]);
            }
        }
        return output;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if(digits.size()==0)
            return output;
        // for(int i=0;i<output.size();i++)
        // {
        //     cout<<output[i]<<" ";
        // }
        return getCombinations(digits,0,output);
    }
};