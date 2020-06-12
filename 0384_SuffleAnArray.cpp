/*Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must 
equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
    vector<int> copy;
    vector<int> shuffled;
    int i;
public:
    Solution(vector<int>& nums) {
        copy=nums;  //copying contents of nums to copy vector
        shuffled=nums;
        i=0;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(shuffled.size()==0)
            return shuffled;
        if(i==shuffled.size())
            i=0;
        int lower=0,upper=shuffled.size()-1;
        int random=lower+(rand()%(upper-lower+1));
        swap(shuffled[random],shuffled[i]);
        i++;
        //rotate(shuffled.begin(),shuffled.begin()+i,shuffled.end());
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */