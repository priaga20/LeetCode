/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    
    int getCount(string s)
    {
        if(s.size()==0)
            return 0;

        int *dp=new int[s.size()+1] ();
        dp[0]=1;  //empty string

        if(s[0]=='0')
            return 0;
        else
            dp[1]=1;
        
        for(int i=2;i<=s.size();i++)
        {
            if(s[i-1] > '0')
                dp[i]=dp[i-1];
            int t=stoi(s.substr(i-2,2));
            if(t<=26 && t>0)
                dp[i]+=dp[i-2];
        }
        return dp[s.size()];
    }
    
    int numDecodings(string s){
        int ans=getCount(s);
        return ans;
    }
};

//     int getCount(string s,int indx,int *dp)
//     {
//         //order of these 3 if conditions should be this only
//         // eg: "0"
//         if(indx==s.length())
//             return 1;
//         if(s[indx]=='0')
//             return 0;
//         if(indx==s.length()-1)
//             return 1;
//         if(dp[indx]>0)
//             return dp[indx];
//         int ways1=getCount(s,indx+1,dp);
//         int ways2=0;
//         if(stoi(s.substr(indx,2))<=26)
//             ways2=getCount(s,indx+2,dp);
//         return dp[indx]=ways1+ways2;
//     }
    
//     int numDecodings(string s){
//         //int dp[s.length()+1];
//         int *dp=new int[s.length()+1] ();
//         int ans=getCount(s,0,dp);
//         return ans;
//     }