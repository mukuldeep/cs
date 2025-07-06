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
struct dt{
    bool isBst;
    int sm,lw,hi;
};
class Solution {
public:
   dt  mxSm(TreeNode* node,int &ans){
        if(node==NULL)return {true,0,100000,-100000};
        int sml;
        dt lans,rans;
        lans=mxSm(node->left,ans);
        rans=mxSm(node->right,ans);
       
        sml=lans.sm+node->val+rans.sm;
        
       if(lans.isBst && rans.isBst && lans.hi < node->val && node->val < rans.lw){
            ans=max(ans,sml);
           if(lans.lw==100000)lans.lw=node->val;
           if(rans.hi==-100000)rans.hi=node->val;
            return {true,sml,lans.lw,rans.hi};
       }else{
            return {false,sml,lans.lw,rans.hi};           
       }
    }
    
    int maxSumBST(TreeNode* root) {
        int ans=0;
        mxSm(root,ans);
    
        return ans;
    }
};