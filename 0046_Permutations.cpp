/*Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

class Solution {
public:
    void getPermutations(vector<int> &nums,vector<vector<int>> &ans,int s)
    {
        if(s==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=s;i<nums.size();i++)
        {
            swap(nums[i],nums[s]);
            getPermutations(nums,ans,s+1);
            swap(nums[i],nums[s]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums,ans,0);
        return ans;
    }
};
