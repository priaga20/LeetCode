/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the 
following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current 
state. The next state is created by applying the above rules simultaneously to every cell in 
the current state, where births and deaths occur simultaneously.

Example:
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

Follow up:

    Could you solve it in-place? Remember that the board needs to be updated at the same time: 
    You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is 
    infinite, which would cause problems when the active area encroaches the border of the array.
    How would you address these problems?
*/

class Solution {
public:
    
    int dx[8]={ -1,-1,-1,0,0,1,1,1};
    int dy[8]={ -1,0,1,-1,1,-1,0,1};
    
    void helper(vector<vector<int>>& board,int i,int j,int n, int m)
    {
        int cs=board[i][j];  //current state
        int cLive=0; //count of live neighbours
        for(int k=0;k<8;k++)
        {
            int x= i+dx[k];
            int y= j+dy[k]; 
            if(x<0 || y<0 || x>=n || y>=m)
                continue;
            if(board[x][y]==1 || board[x][y]==99)
                cLive++;
        }
        if(cs==1 && (cLive<2 || cLive>3))
            board[i][j]=99;
        if(cs==0 && cLive==3)  
            board[i][j]=88;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                helper(board,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==99)
                    board[i][j]=0;
                else if(board[i][j]==88)
                    board[i][j]=1;
            }
        }
    }
    
    
    //using extra space
//     int dx[8]={ -1,-1,-1,0,0,1,1,1};
//     int dy[8]={ -1,0,1,-1,1,-1,0,1};
    
//     int helper(vector<vector<int>>& board,int i,int j,int n, int m, vector<int> &ans)
//     {
//         int cs=board[i][j];  //current state
//         int cLive=0; //count of live neighbours
//         for(int k=0;k<8;k++)
//         {
//             int x= i+dx[k];
//             int y= j+dy[k]; 
//             if(x<0 || y<0 || x>=n || y>=m)
//                 continue;
//             if(board[x][y]==1)
//                 cLive++;
//         }
//         if(cs==1)
//         {
//             if(cLive<2)
//                 return 0;
//             if(cLive==2 || cLive==3)
//                 return 1;
//             if(cLive>3)
//                 return 0;
//         }
//         if(cLive==3)
//             return 1;
//         return cs;
//     }
    
//     void gameOfLife(vector<vector<int>>& board) {
//         int n=board.size();
//         int m=board[0].size();
//         vector<int> ans;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 int k=helper(board,i,j,n,m,ans);
//                 ans.push_back(k);
//             }
//         }
//         int k=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 board[i][j]=ans[k];
//                 k++;
//             }
//         }
//     }
};
