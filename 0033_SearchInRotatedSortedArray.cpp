/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[s]<=nums[mid])  //left half sorted
            {
                if(target<=nums[mid] && target>=nums[s])
                    e=mid-1;
                else
                    s=mid+1;
            }
            else if(nums[e]>=nums[mid])  //right half sorted
            {
                if(target>=nums[mid] && target<=nums[e])
                    s=mid+1;
                else
                    e=mid-1;
            }
        }
        return -1;
    }
};
