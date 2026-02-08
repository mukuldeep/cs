class Solution {

    int height(TreeNode* node, bool& isBalanced){

        if(node==NULL){
            return 0;
        }

        int leftHeight = 1 + height(node->left, isBalanced);
        int rightHeight = 1 + height(node->right, isBalanced);

        if(abs(rightHeight - leftHeight)>1){
            isBalanced = false;
        }

        return max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        height(root, isBalanced);
        return isBalanced;
    }
};