package offl.leetcodes;

public class LongestIncreasingSubsequenceii {

    static class DynamicMaxTree {
        static class Node {
            int start, end;
            int max;
            Node left, right;

            Node(int start, int end) {
                this.start = start;
                this.end = end;
                this.max = 1;
            }
        }

        Node root;

        public DynamicMaxTree(int start, int end) {
            root = new Node(start, end);
        }

        void update(Node node, int idx, int val) {
            if (node.start == node.end) {
                node.max = val;
                return;
            }

            int mid = node.start + (node.end - node.start) / 2;

            if (idx <= mid) {
                if (node.left == null)
                    node.left = new Node(node.start, mid);
                update(node.left, idx, val);
            } else {
                if (node.right == null)
                    node.right = new Node(mid + 1, node.end);
                update(node.right, idx, val);
            }

            int leftMax = (node.left != null ? node.left.max : 1);
            int rightMax = (node.right != null ? node.right.max : 1);
            node.max = Math.max(leftMax, rightMax);
        }

        int query(Node node, int l, int r) {
            if (node == null || r < node.start || l > node.end)
                return 0; // no overlap
            if (l <= node.start && node.end <= r)
                return node.max; // full overlap

            int leftMax = query(node.left, l, r);
            int rightMax = query(node.right, l, r);
            return Math.max(leftMax, rightMax);
        }

        void update(int idx, int val) {
            update(root, idx, val);
        }

        int query(int l, int r) {
            return query(root, l, r);
        }
    }



    public static int lengthOfLIS(int[] nums, int k) {


        DynamicMaxTree tree = new DynamicMaxTree(0, 100005);
        int lis_len = 1;

        tree.update(nums[0],1);

        for(int num : nums){
            int mx_in_range = tree.query(Math.max(0,num-k), num-1);
            //System.out.println("max among "+(num-k)+" "+(num-1)+" ="+mx_in_range);
            tree.update(num,mx_in_range+1);
            lis_len = Math.max(lis_len, mx_in_range+1);
        }

        return lis_len;
    }


    public static void main(String[] args){
        int[] nums = {1, 2, 3, 4, 7, 2, 6, 10, 13, 7, 23, 8};
        int k = 3;

        int ans = lengthOfLIS(nums, k);

        System.out.println(ans);
    }
}
