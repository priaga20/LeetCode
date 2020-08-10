/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol=false;
        
        for(int i=0;i<matrix.size();i++)
        {
            
      // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // For this solution we are using an additional variable for the first column
      // and using matrix[0][0] for the first row.
            if(matrix[i][0]==0)
                isCol=true; //first col has to be all zero if any value in first col is zero 
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;  //ith row has to be marked 0
                    matrix[0][j]=0;  //jth col has to be marked 0
                }
            }
        }
        // Iterate over the array once again and using the first row and first column, 
        //update the elements.
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        //check if first row needs to be set to zero as well
        if(matrix[0][0]==0)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                matrix[0][j]=0;
            }
        }
        //check if first col needs to be set to zero as well
        if(isCol)
        {
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};