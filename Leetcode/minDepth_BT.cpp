/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the 
 * root node down to the nearest leaf node.
 */
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right)
            return minDepth(root->right)+1;
        if(root->right==NULL && root->left)
            return minDepth(root->left)+1;    
        return min(minDepth(root->left),minDepth(root->right))+1;    
    }
};
