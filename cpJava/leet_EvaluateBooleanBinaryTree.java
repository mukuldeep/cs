package offl.leetcodes;

public class leet_EvaluateBooleanBinaryTree {
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
    public boolean evaluateTree(TreeNode root) {
        if(root.val<2){
            return (root.val == 1)?true:false;
        }

        boolean left = evaluateTree(root.left);
        boolean right = evaluateTree(root.right);

        if(root.val == 2){
            return (left | right);
        }

        return (left & right);
    }
}
