/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    TreeNode ans;

    private void storeDepth(TreeNode node, int d, int[] depth){
        if(node==null)
            return;

        depth[node.val] = d;
        storeDepth(node.left, d+1, depth);
        storeDepth(node.right, d+1, depth);
    }

    private int mxDepthCnt(TreeNode node, int mxd, int mxTotalCnt, int[] depth){
        if(node==null)
            return 0;

        int mxCnt = 0;
        if(depth[node.val] == mxd)
            mxCnt++;
        mxCnt += mxDepthCnt(node.left, mxd, mxTotalCnt, depth);
        mxCnt += mxDepthCnt(node.right, mxd, mxTotalCnt, depth);

        if(ans == null && mxCnt == mxTotalCnt){
            ans = node;
        }

        return mxCnt;
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        int[] depth = new int[505];
        Arrays.fill(depth,-1);
        storeDepth(root, 1, depth);

        int mxDepth = 0;
        for(int i=0; i<505; i++){
            mxDepth = Math.max(mxDepth, depth[i]);
        }
        int mxCnt = 0;
        for(int i=0; i<505; i++){
            if(depth[i] == mxDepth){
                mxCnt++;
            }
        }

        //System.out.println("mxDepth = "+mxDepth);

        ans = null;

        mxDepthCnt(root, mxDepth, mxCnt, depth);

        return ans;


    }
}