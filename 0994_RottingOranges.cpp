/*In a given grid, each cell can have one of three values:

    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Note:

    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.
*/

class Solution {
private:
    struct node{
        int time,x,y;  //time frame and position of rotten oranges
    };
    
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        
        int totalFresh=0;  //keeping track of fresh oranges
        int timeFrame=0;
        
        queue<node> q;
        
        // Store all the inital rotten oranges 
        for (int i=0;i<grid.size();i++) 
        {
            for (int j=0;j<grid[i].size();j++) 
            {
                if (grid[i][j] == 2) {
                    q.push(node{0, i, j});
                }
                else if (grid[i][j] == 1) {
                    totalFresh++; // count the no of fresh oranges
                }
            }
        }
        
        while(!q.empty())
        {
            node f = q.front();
            q.pop();
            timeFrame=f.time;
            int i=f.x;
            int j=f.y;
            
            for(int k=0;k<4;k++)
            {
                int x = i+dx[k];
                int y = j+dy[k];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[i].size() && grid[x][y] == 1) {
                    grid[x][y] = 2; // mark as rotten
                    q.push(node{f.time+1, x, y}); // update queue
                    totalFresh -= 1; // reduce fresh orange count
                }
            }
        }
        
        return (totalFresh==0)?timeFrame:-1;
    }
};
