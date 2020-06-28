/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    void floodFill(vector<vector<char>>& board,int i,int j,int n,int m,char prevChar,char newChar)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(board[i][j]!=prevChar)
            return;
        board[i][j]=newChar;
        for(int k=0;k<4;k++)
        {
            floodFill(board,i+dx[k],j+dy[k],n,m,prevChar,newChar);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='-';
            }
        }
        //first row
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='-')
                floodFill(board,0,j,n,m,'-','O');
        }
        //last row
        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='-')
                floodFill(board,n-1,j,n,m,'-','O');
        }
        //first column
        for(int i=1;i<n-1;i++)
        {
            if(board[i][0]=='-')
                floodFill(board,i,0,n,m,'-','O');
        }
        //last column
        for(int i=1;i<n-1;i++)
        {
            if(board[i][m-1]=='-')
                floodFill(board,i,m-1,n,m,'-','O');
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='-')
                    board[i][j]='X';
            }
        }
    }
};