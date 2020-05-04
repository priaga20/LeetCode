/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

/*Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(m.find(rem)!=m.end())
            {
                output.push_back(m[rem]);
                output.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return output;
    }
};
