/*Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order. */

class Solution {
public:
    
    int getPindex(unordered_map<int,int> &m, int* unique,int s,int e)
    {
        int i=s,j=s;
        int pivotFreq=m[unique[e]];
        while(j<e)
        {
            if(m[unique[j]]<=pivotFreq)
            {
                swap(unique[i],unique[j]);
                i++;
            }
            j++;
        }
        swap(unique[i],unique[e]);
        return i;
    }
    
    void quickSelect(unordered_map<int,int> &m,int* unique, int lower,int upper, int indx)
    {
        if(lower==upper)
            return;
        //generating pivot randomly bcoz random is best 
        //since we have a equal likelihood to pick any element.
        int pivot= lower + rand()%(upper-lower+1);
        //swapping so that last element is our pivot element
        swap(unique[pivot],unique[upper]);
        
        int partition= getPindex(m,unique,lower,upper);
            
        //binary search concept
        if(partition==indx)
            return;
        else if(partition<indx)
            quickSelect(m,unique,partition+1,upper,indx);
        else
            quickSelect(m,unique,lower,partition-1,indx);
    }
    
     vector<int> topKFrequent(vector<int>& nums, int k){
        if(k==nums.size())
            return nums;
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
         
        int n=m.size();  //no of unique elements in nums 
        int* unique = new int [n];
         int i=0;
         for(auto a: m)
         {
             unique[i]=a.first;
             i++;
         }
         
         quickSelect(m,unique,0,n-1,n-k);
         
         vector<int> ans;
         for(int i=n-k;i<n;i++)
         {
             ans.push_back(unique[i]);
         }
         return ans;
     }
    
//     using heaps
    
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         if(k==nums.size())
//             return nums;
        
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++)
//         {
//             m[nums[i]]++;
//         }
        
//         priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
//         for(auto i : m)
//         {
//             pq.push(make_pair(i.second,i.first));
//             if(pq.size()>k)
//                 pq.pop();
//         }
        
//         vector<int> ans;
//         for(int i=0;i<k;i++)
//         {
//             pair<int,int> p = pq.top();
//             pq.pop();
//             ans.push_back(p.second);
//         }
//         return ans;
//     }
};