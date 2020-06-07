/*Given an integer array, you need to find one continuous subarray that if you only sort this 
subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted 
in ascending order.

Note:

    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=. */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=0,end=0,flag=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                start=i;
                flag=1;
                break;
            }
        }
        if(!flag)
            return 0;  //array already sorted
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]<nums[i-1])
            {
                end=i;
                break;
            }
        }
        int minele=nums[start],maxele=nums[start];
        for(int i=start+1;i<=end;i++)
        {
            minele=min(nums[i],minele);
            maxele=max(nums[i],maxele);
        }
        for(int i=0;i<start;i++)
        {
            if(nums[i]>minele)
            {
                start=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>end;i--)
        {
            if(nums[i]<maxele)
            {
                end=i;
                break;
            }
        }
        return end-start+1;
    }
};