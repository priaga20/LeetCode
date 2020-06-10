/*Given an array nums of n integers where n > 1,  return an array output such that 
output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of 
the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as 
extra space for the purpose of space complexity analysis.) */

class Solution {
public:
    
    //O(n) time O(1) space
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<n;i++)
        {
            ans.push_back(ans[i-1]*nums[i-1]);
        }
        int r=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*r;
            r=r*nums[i];
        }
        return ans;
    }
    
    //O(n) space and time
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n=nums.size();
    //     int *left = new int[n];
    //     int *right = new int[n];
    //     //vector<int> left,right;
    //     left[0]=1;
    //     for(int i=1;i<n;i++)
    //     {
    //         left[i]=left[i-1]*nums[i-1];
    //     }
    //     right[n-1]=1;
    //     for(int i=n-2;i>=0;i--)
    //     {
    //         right[i]=right[i+1]*nums[i+1];
    //     }
    //     vector<int> ans;
    //     for(int i=0;i<n;i++)
    //     {
    //         ans.push_back(left[i]*right[i]);
    //     }
    //     delete [] left;
    //     delete [] right;
    //     return ans;
    // }
};