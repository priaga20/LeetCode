/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

 

Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3
*/

class Solution {
public:
    
    bool searchWord(vector<vector<char>>& board, string word, int i,int j,int n,int m,int s)
    {
        if(s==word.size())
            return true;
        
        if(i>=n || j>=m || i<0 || j<0 || board[i][j]!=word[s] || board[i][j]=='\0')
            return false;
        
        char t=board[i][j];
        board[i][j]='\0';
        
        
        if(searchWord(board,word,i,j-1,n,m,s+1) || searchWord(board,word,i,j+1,n,m,s+1) || searchWord(board,word,i+1,j,n,m,s+1) || searchWord(board,word,i-1,j,n,m,s+1))
            return true;
        
        //backtracking
        board[i][j]=t;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(searchWord(board,word,i,j,n,m,0))
                    return true;
            }
        }
        return false;
    }
};
