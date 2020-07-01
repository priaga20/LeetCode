/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int minVal = nums[0]; 
        int maxVal = nums[0]; 
        int max_product = nums[0]; 

        for (int i = 1; i < nums.size(); i++) { 

            // When multiplied by -ve number, maxVal becomes minVal and minVal becomes maxVal. 
            if (nums[i] < 0) 
                swap(maxVal, minVal); 
            // maxVal and minVal stores the product of subarray ending at arr[i]. 
            maxVal = max(nums[i], maxVal * nums[i]); 
            minVal = min(nums[i], minVal * nums[i]); 
            // Max Product of array. 
            max_product = max(max_product, maxVal); 
        } 
        // Return maximum product found in array. 
        return max_product; 
    }
};
