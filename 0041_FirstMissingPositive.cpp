/*Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //empty vector
        if(n==0)
            return 1;
        
        //segregating +ve and -ve numbers
        int neg=n;   //stores the position of starting of negative number in the vector
        int i=0;
        while(i<neg)
        {
            if(nums[i]<=0)
            {
                swap(nums[i],nums[--neg]);
            }
            else
            {
                i++;
            }
            //i++;                
        }
        
        //all numbers are -ve
        if(nums[0]<0)
            return 1;
        
        // Mark nums[i] as visited by making nums[nums[i] - 1] negative. 
        // Note that 1 is subtracted because index start from 0 and positive numbers start from 1 
        for(int i=0;i<neg;i++)
        {
            if(abs(nums[i])-1>=0 && abs(nums[i])-1<n)
            {
                if(nums[abs(nums[i])-1]>0)
                {
                    nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
                }
            }
        }
        
        //scanning for first positive number
        for(int i=0;i<neg;i++)
        {
            //cout<<nums[i]<<endl;
            if(nums[i]>=0)
            {
                return i+1;
            }
        }
        return neg+1;
    }
};