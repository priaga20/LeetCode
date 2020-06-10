 /*Given n pairs of parentheses, write a function to generate all combinations of 
 well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/

class Solution {
public:
    
    void backTrack(vector<string> &output,string curr,int open,int close,int n)
    {
        if(curr.size()==2*n)
        {
            output.push_back(curr);
            return;
        }
        if(open<n)  //more ( can be added
            backTrack(output,curr+"(",open+1,close,n);
        if(close<open)  //more ) can be added
            backTrack(output,curr+")",open,close+1,n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backTrack(output,"",0,0,n);
        return output;
    }
};
