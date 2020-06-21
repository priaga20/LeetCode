/*Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        queue<TreeNode*> q;
        stack<TreeNode*> s;

        int l=1;
        q.push(root);
        q.push(NULL);  //to mark end of level
        
        vector<int> v;
        while(!q.empty())
        {
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL)
            {
                if(v.size()!=0)
                {
                    ans.push_back(v);   
                    v.clear();
                }
                while(!s.empty())
                {
                    TreeNode* t=s.top();
                    s.pop();
                    v.push_back(t->val);
                }
                if(l%2==0)
                {
                    ans.push_back(v);
                    v.clear();
                }
                l++;
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                if(l%2==1)
                    v.push_back(f->val);
                else
                    s.push(f);
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
        return ans;
    }
};