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

    private long getSum(TreeNode node){
        if(node == null){
            return 0;
        }

        long sm = node.val;
        sm += getSum(node.left);
        sm += getSum(node.right);
        return sm;
    }

    private long getMxP(TreeNode node, long[] ans, long tsum){
        if(node == null){
            return 0;
        }

        long sm = node.val;
        sm += getMxP(node.left, ans, tsum);
        sm += getMxP(node.right, ans, tsum);

        ans[0] = Math.max(ans[0],
                          sm * (tsum-sm)
                          );
        
        return sm;
    }
    
    public int maxProduct(TreeNode root) {
        long sm = getSum(root);
        long[] ans = new long[]{0};
        getMxP(root, ans, sm);

        ans[0] %= 1_000_000_007;
        return (int)ans[0];
        
    }
}