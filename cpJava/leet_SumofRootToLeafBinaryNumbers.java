package offl.leetcodes;

public class leet_SumofRootToLeafBinaryNumbers {

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

    void sumRootToLeafUtil(TreeNode node, int num, int[] sum) {
        num<<=1;
        if(node.val == 1){
            num++;
        }
        if(node.left == null && node.right == null){
            sum[0]+=num;
        }

        if(node.left!=null){
            sumRootToLeafUtil(node.left, num, sum);
        }

        if(node.right!=null){
            sumRootToLeafUtil(node.right, num, sum);
        }

    }

    public int sumRootToLeaf(TreeNode root) {
        int[] ans = new int[]{0};
        sumRootToLeafUtil(root, 0, ans);
        return ans[0];
    }
}
