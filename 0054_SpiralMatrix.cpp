/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        int sr=0,sc=0,er=matrix.size()-1,ec=matrix[0].size()-1;
        while(sr<=er && sc<=ec)
        {
            for(int i=sc;i<=ec;i++)
            {
                ans.push_back(matrix[sr][i]);
            }
            sr++;
            for(int i=sr;i<=er;i++)
            {
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            if(er>=sr)  //if er is not already printed
            {
                for(int i=ec;i>=sc;i--)
                {
                    ans.push_back(matrix[er][i]);
                }
                er--;
            }
            if(ec>=sc)  //if sc is not already printed
            {
                for(int i=er;i>=sr;i--)
                {
                    ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        return ans;
    }
};