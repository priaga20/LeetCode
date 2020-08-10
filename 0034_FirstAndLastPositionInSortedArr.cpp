/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    nums is a non decreasing array.
    -10^9 <= target <= 10^9
*/

class Solution {
public:
    int search(vector<int> &nums,int t,int bound)
    {
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==t)
            {
                ans=mid;
                if(bound)  //trying to find upper bound
                    s=mid+1;
                else       //trying to find lower bound
                    e=mid-1;
            }
            else if(nums[mid]>t)
            {
                e=mid-1;
            }
            else if(nums[mid]<t)
            {
                s=mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(search(nums,target,0));  //bound=0 means lower bound
        if(ans[0]==-1)
        {
            ans.push_back(-1);
            return ans;
        }           
        ans.push_back(search(nums,target,1));  //bound=1 means upper bound
        return ans;
    }
};
