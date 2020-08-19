/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    
    // void getPermutations(vector<int> &nums, int s, set<vector<int>> &output)
    // {
    //     if(s==nums.size())
    //     {
    //         output.insert(nums);
    //         return;
    //     }
        
    //     for(int i=s;i<nums.size();i++)
    //     {
    //         swap(nums[s],nums[i]);
    //         getPermutations(nums,s+1,output);
    //         swap(nums[s],nums[i]);
    //     }
    // }
    
    void getPermutations(vector<int> &nums, int s, set<vector<int>> &output)
    {
        sort(nums.begin(),nums.end());
        do{
            output.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        getPermutations(nums,0,s);
        vector<vector<int>> ans;
        for(auto i:s)
        {
            ans.push_back(i);   
        }
        return ans;
    }
};