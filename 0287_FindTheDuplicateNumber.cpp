/*Given an array nums containing n + 1 integers where each integer is between 1 and n 
(inclusive), prove that at least one duplicate number must exist. Assume that there is 
only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2

Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.*/



class Solution {
public:
    
    //O(n)-time      O(1)-space
    int findDuplicate(vector<int>& nums) {
        int t= nums[0],h=nums[0];
        do
        {
            t=nums[t];
            h=nums[nums[h]];
        } while(t!=h);
         
        t=nums[0];
        while(t!=h)
        {
            t=nums[t];
            h=nums[h];
        }
        return h;
        
        
        //sorting modifies the array and we can't modify it
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     int s=i+1,e=nums.size()-1;
        //     int key=nums[i];
        //     while(s<=e)
        //     {
        //         int mid=(s+e)/2;
        //         if(nums[mid]==key)
        //             return key;
        //         else if(nums[mid]<key)
        //             s=mid+1;
        //         else
        //             e=mid-1;
        //     }
        // }
        // return 0;
        
        
        
        // this approach will not work bcoz many copies of duplicate no can be there
        // int n=nums.size();
        // int sum1=0;
        // for(auto a : nums)
        // {
        //     sum1+=a;
        // }
        // int sum2= n*(n-1) /2;
        // return sum1-sum2;
    }
};