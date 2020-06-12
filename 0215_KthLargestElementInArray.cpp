/*Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.*/


class Solution {
public:
    
    int getPindex(vector<int> &nums,int s,int e)
    {
        int i=s,j=s;
        int pivotEle=nums[e];
        while(j<e)
        {
            if(nums[j]<=pivotEle)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        swap(nums[i],nums[e]);
        return i;
    }
    
    void quickSelect(vector<int> &nums,int lower,int upper,int indx)
    {
        //generating pivot randomly bcoz random is best 
        //since we have a equal likelihood to pick any element.
        int pivot= lower + rand()%(upper-lower+1);
        //swapping so that last element is our pivot element
        swap(nums[pivot],nums[upper]);

        int partition= getPindex(nums,lower,upper);

        //binary search concept
        if(partition==indx)
            return;
        else if(partition<indx)
            quickSelect(nums,partition+1,upper,indx);
        else
            quickSelect(nums,lower,partition-1,indx);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size(),indx=n-k;
        quickSelect(nums,0,n-1,indx);
        return nums[indx];
    }
};