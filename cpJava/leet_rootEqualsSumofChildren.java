package offl.leetcodes;

public class leet_rootEqualsSumofChildren {
    public class TreeNode {
        int val;
        leet_EvaluateBooleanBinaryTree.TreeNode left;
        leet_EvaluateBooleanBinaryTree.TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, leet_EvaluateBooleanBinaryTree.TreeNode left, leet_EvaluateBooleanBinaryTree.TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public boolean checkTree(TreeNode root) {
        return (root.val == (root.left.val+root.right.val));
    }

}
