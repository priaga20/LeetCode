/*Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

class Solution {
public:
    void getSubsets(vector<int>& nums,int e,vector<vector<int>> &ans)
    {
        if(e<0)
        {
            vector<int> t;
            ans.push_back(t);
            return;
        }
        getSubsets(nums,e-1,ans);
        int l=ans.size();
        for(int i=0;i<l;i++)
        {
            //By passing vector as constructor. At the time of declaration of vector, 
            //passing an old initialized vector, copies the elements of passed vector 
            //into the newly declared vector. They are deeply copied.
            vector<int> t(ans[i]);
            t.push_back(nums[e]);
            ans.push_back(t);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        getSubsets(nums,nums.size()-1,ans);
        return ans;
    }
};