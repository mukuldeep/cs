package offl.leetcodes;

import java.util.List;

public class leet_MaximumDepthofNaryTree {
    class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    };

    int maxDepthUtil(Node node, int d) {
        int f = d;
        for(Node ch: node.children){
            f = Math.max(f,maxDepthUtil(ch,d+1));
        }
        return f;
    }

    public int maxDepth(Node root) {
        if(root == null){
            return 0;
        }
        return maxDepthUtil(root,1);
    }
}
