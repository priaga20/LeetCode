/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]  */


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        if(numRows==0)
            return output;
        output.push_back(vector<int>({1}));
        if(numRows==1)
            return output;
        output.push_back(vector<int>({1,1}));
        for(int i=2;i<numRows;i++)
        {
            vector<int> v;
            v.push_back(1);
            for(int j=0;j<i-1;j++)
            {
                int t=output[i-1][j]+output[i-1][j+1];
                v.push_back(t);
            }
            v.push_back(1);
            output.push_back(v);
        }
        return output;
    }
};

