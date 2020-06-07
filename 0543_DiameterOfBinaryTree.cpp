 /*Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a 
 binary tree is the length of the longest path between any two nodes in a tree. This path may or may not 
 pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Pair{
  public:
    int h;  //height
    int d;  //diameter
};


class Solution {
public:
    Pair diameter(TreeNode* root)
    {
        Pair p;
        if(root==NULL)
        {
            p.h=0;
            p.d=0;
            return p;
        }
        
        Pair left=diameter(root->left);
        Pair right=diameter(root->right);
        
        p.h=1+max(left.h,right.h);
        p.d=max((left.h+right.h),max(left.d,right.d));
        
        return p;
    }
    
    int diameterOfBinaryTree(TreeNode* root){
        Pair p= diameter(root);
        return p.d;
    }
    
    /*int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        int op1=height(root->left)+height(root->right);
        int op2=diameterOfBinaryTree(root->left);
        int op3=diameterOfBinaryTree(root->right);
        return max(op1, max(op2,op3));
    }*/
};