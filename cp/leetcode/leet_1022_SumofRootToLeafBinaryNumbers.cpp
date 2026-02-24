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
    int sumRootToLeaf(TreeNode* root, int pre) {

        pre <<= 1;    
        if(root -> val == 1){
            pre++;
        }

        if(root->left == NULL && root->right == NULL)
            return pre;

        int sm = 0;
        if(root->left != NULL)
            sm += sumRootToLeaf(root->left, pre);

        if(root->right != NULL)
            sm += sumRootToLeaf(root->right, pre);

        return sm;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }
};