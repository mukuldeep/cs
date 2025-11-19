package offl.leetcodes;

public class leet_SumofPrefixScoresofStrings {

    static class TrieCnt {
        static class Node {
            Node[] nxt = new Node[26];
            boolean end = false;
            int cnt = 0;
        }

        private Node root;// = new Node();


        public TrieCnt(){
            root = new Node();
        }

        public void insert(String s) {
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null) {
                    cur.nxt[idx] = new Node();
                }

                cur = cur.nxt[idx];
                cur.cnt++;
            }
            cur.end = true;
        }

        public boolean search(String s) { // full word
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null)
                    return false;
                cur = cur.nxt[idx];
            }
            return cur.end;
        }

        public boolean startsWith(String s) { // prefix only
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null)
                    return false;
                cur = cur.nxt[idx];
            }
            return true;
        }

        public int startsWithCount(String s) { // prefix + word
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null)
                    return 0;
                cur = cur.nxt[idx];
            }
            return cur.cnt;
        }

        public int countAllPrefixOccurance(String s) {
            int ans = 0;
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null)
                    return ans;

                cur = cur.nxt[idx];
                ans += cur.cnt;
            }

            return ans;
        }


    }


    public static int[] sumPrefixScores(String[] words) {
        TrieCnt trieCnt = new TrieCnt();
        for(String word : words){
            trieCnt.insert(word);
        }

        int[] ans = new int[words.length];

        for(int i=0; i< words.length; i++){
            ans[i] = trieCnt.countAllPrefixOccurance(words[i]);
        }

//        System.out.println("a="+trieCnt.startsWithCount("a"));
//        System.out.println("ab="+trieCnt.startsWithCount("ab"));
//        System.out.println("abc="+trieCnt.startsWithCount("abc"));

        return ans;
    }

    public static void main(String[] args){

        //String[] strs = {"abc","ab","bc","b"};
        String[] strs = {"abcd"};

        int[] ans = sumPrefixScores(strs);
        System.out.println();
        for(int num: ans){
            System.out.print(num+" ");
        }System.out.println();



    }
}
