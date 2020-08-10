/*Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

    intervals[i][0] <= intervals[i][1]
*/

class Solution {
public:
    
    /*Complexity Analysis
    Time complexity : O(nlog⁡n)
    Other than the sort invocation, we do a simple linear scan of the list, so the runtime is
    dominated by the O(nlgn) complexity of sorting.

    Space complexity : O(1)O(1)O(1) (or O(n)O(n)O(n))
    If we can sort intervals in place, we do not need more than constant additional space.
    Otherwise, we must allocate linear space to store a copy of intervals and sort that.*/
    
    static bool myCompare(vector<int> v1, vector<int> v2)
    {
        return v1[0]<v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {  
        
        if(intervals.size()==0)
            return intervals;
        if(intervals.size()==1)
            return intervals;
        
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),myCompare);
        
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.size()==0 || intervals[i][0] > ans[ans.size()-1][1])  //empty or non over lapping
                ans.push_back(intervals[i]);
            else
            {
                //overlapping there
                int s=ans[ans.size()-1][0];
                int e=max(intervals[i][1] , ans[ans.size()-1][1]);  //[ [1,4], [2,3]]
                ans.pop_back();
                ans.push_back(vector<int> {s,e});
            }
        }
        return ans;
    }
};           

