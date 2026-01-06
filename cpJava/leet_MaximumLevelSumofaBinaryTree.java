package offl.dloc;

import java.util.HashMap;

public class leet_MaximumLevelSumofaBinaryTree {


      //Definition for a binary tree node.
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

      HashMap<Integer, Integer> hSum;
      public void dfs(TreeNode node, int depth){
          if(node == null){
              return;
          }

          // add current value to hSum
          if(hSum.containsKey(depth)) {
              hSum.put(depth, hSum.get(depth) + node.val);
          }else{
              hSum.put(depth, node.val);
          }

          //recurse
          dfs(node.left, depth+1);
          dfs(node.right, depth+1);
      }

        public int maxLevelSum(TreeNode root) {
          hSum = new HashMap<>();
          dfs(root,1);

          int maxSum = -1_000_000;
          int dep = -1;

          for(int i=1; i<10_005; i++){
              if(hSum.containsKey(i)){
                  if(hSum.get(i) > maxSum){
                      maxSum = hSum.get(i);
                      dep = i;
                  }
              }else{
                  break;
              }
          }

          return dep;
        }


    public static void main(String[] args){
//        long num1 = 42;
//
//        int[] nums = {2, 7, 11, 15};
//        int target = 9;
//
//        System.out.println();
    }

}
