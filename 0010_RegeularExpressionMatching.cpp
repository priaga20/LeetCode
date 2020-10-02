/*Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        int** dp=new int *[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[m+1];
        }
        dp[0][0]=1;
        //0th column - when pattern is empty 
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<endl;
            dp[i][0]=0;
        }
        //0th row - when string is empty - can be true or false depending on the pattern(Eg: a* or a*b* matches with empty string and hence will be true)
        for(int i=1;i<=m;i++)
        {
            //cout<<i<<endl;
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-2];
            else
                dp[0][i]=0;
            //cout<<"bye"<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cout<<i<<" "<<j<<endl;
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    //taking 0 occurence of character before *
                    dp[i][j]=dp[i][j-2];
                    //if it gives false then check by taking it into account
                    //see if the s[i]==p[j-1], i.e, character before * matches ith character of string or the character before * is . then look for the matching of the pattern till j and string till i-1
                    if(dp[i][j]==0)
                    {
                        if(s[i-1]==p[j-2] || p[j-2]=='.')
                        {
                            dp[i][j]=dp[i-1][j];
                        }
                    }
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
        
    }
};
