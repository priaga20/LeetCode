/*You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from 
robbing each of them is that adjacent houses have security system connected and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.*/

class Solution {
public:
    //Bottom Up DP
    int rob(vector<int>& nums) {
        int dp[1000]={};
        int n=nums.size();
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n+1;i++)
        {
            
            dp[i]=max(nums[i-2]+dp[i-2],dp[i-1]);
        }
        return dp[n+1];
    }
    
    //Top Down DP
    /*int dp[100]={};
    int helpRob(vector<int> nums,int s)
    {
        if(s>nums.size()-1)
            return 0;
        if(dp[s]!=0)
            return dp[s];
        int op1=nums[s]+helpRob(nums,s+2);
        int op2=helpRob(nums,s+1);
        return dp[s]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int ans=helpRob(nums,0);
        return ans;
    }*/
};