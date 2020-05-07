/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>

class Solution {
public:
    bool isMirror(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL && r2==NULL)
            return true;
        if(r1==NULL && r2!=NULL)
            return false;
        if(r1!=NULL && r2==NULL)
            return false;
        if(r1->val==r2->val && isMirror(r1->left,r2->right) && isMirror(r1->right,r2->left))
            return true;
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        //recursive
        return isMirror(root,root);
    }
};
