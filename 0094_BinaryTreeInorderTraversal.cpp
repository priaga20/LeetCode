/*Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?*/

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
    //using iteration
    
    //using morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            //if left is NULL then push curr to v and go to right
            if(curr->left == NULL)
            {
                v.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                //find inorder predecessor i.e. rightmost node in left subtree
                TreeNode* pred= curr->left;
                //to find pred keep going to right till right node is not NULL
                //or it is not equal to curr
                while(pred->right!=NULL && pred->right!=curr)
                {
                    pred=pred->right;
                }
                //if right node is NULL then go left after establishing link with curr
                if(pred->right==NULL)
                {
                    pred->right = curr;
                    //v.push_back(curr->val);  //for preOrder
                    curr=curr->left;
                }
                else
                {
                    //left is already visited, go right after visiting curr
                    pred->right=NULL;
                    v.push_back(curr->val);  //remove this line for preOrder
                    curr=curr->right;
                }
            }
        }
        return v;
    }
    
    
    
    //using stack O(n)-time and space
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;               
            }
            curr=s.top();
            s.pop();
            output.push_back(curr->val);
            curr=curr->right;
        }
        return output;
    }*/

    
    
    //using recursion
    /*void inOrder(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inOrder(root,output);
        return output;
    }*/
};
