/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5  */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* arrayToBST(vector<int>& nums,int s,int e)
    {
        if(s>e)
            return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode;
        root->val=nums[mid];
        root->left=arrayToBST(nums,s,mid-1);
        root->right=arrayToBST(nums,mid+1,e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums,0,nums.size()-1);
    }
};