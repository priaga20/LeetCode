/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            // Never let i refer to the same value twice to avoid duplicates.
            if (i != 0 && nums[i] == nums[i - 1]) 
                continue;
            int l=i+1;
            int r=n-1;
            int remSum=0-nums[i];
            while(l<r)
            {
                if(nums[l]+nums[r]==remSum)
                {
                    result.push_back(vector<int>({nums[i],nums[l],nums[r]}));   
                    // to avoid duplicates
                    l++;
                    while(l<r && nums[l-1]==nums[l])
                        l++;
                }
                else if(nums[l]+nums[r]<remSum)
                     l++;
                else
                    r--;
            }
        }
        return result;
    }
};
