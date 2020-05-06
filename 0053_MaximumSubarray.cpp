/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,ms=0,max_ele=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            cs+=nums[i];
            if(cs<0)
                cs=0;
            ms=max(ms,cs);
            max_ele=max(max_ele,nums[i]);
        }
        if(ms==0)
            return max_ele;
        else
            return ms;
    }
};
