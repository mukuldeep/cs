package offl.leetcodes;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class leet_NumberofValidWordsforEachPuzzle {

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
                //cur.cnt++;
                cur = cur.nxt[idx];

            }
            cur.cnt++;
            cur.end = true;
        }

        public int searchCnt(String s) { // full word count
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null)
                    return 0;
                cur = cur.nxt[idx];
            }
            return cur.cnt;
        }

    }

    static String minimizeString(String str){
        StringBuilder ans = new StringBuilder();
        char[] sortedStr = str.toCharArray();
        Arrays.sort(sortedStr);

        char lastCh =' ';
        for(char ch: sortedStr){
            if(lastCh!=ch){
                ans.append(ch);
            }
            lastCh = ch;
        }
//        System.out.println(String.copyValueOf(sortedStr));
//        System.out.println(ans);
        return ans.toString();
    }

    static void allSeqUtil(String str, char startCh, ArrayList<String> seqs, int ind, String soFar){
        if(ind>=str.length()){
            seqs.add(soFar);
            return;
        }
        //select the char
        allSeqUtil(str,startCh,seqs,ind+1,soFar+str.charAt(ind));

        if(str.charAt(ind) != startCh){
            //not select the char
            allSeqUtil(str,startCh,seqs,ind+1,soFar);
        }
    }

    static ArrayList<String> allSeq(String str, char startCh){
        ArrayList<String> seqs = new ArrayList<>();
        allSeqUtil(str,startCh,seqs,0,"");
        return seqs;
    }


    public static List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        List<Integer> ans = new ArrayList<>();

        TrieCnt trieCnt = new TrieCnt();

        for(String word: words){
            word = minimizeString(word);
            if(word.length()<=7) {
                trieCnt.insert(word);
            }
        }

        for(int i=0; i<puzzles.length; i++){
            String puzzle = minimizeString(puzzles[i]);

            int matchCnt = 0;
            //generate all subsequences
            ArrayList<String> seqs = allSeq(puzzle,puzzles[i].charAt(0));
            //System.out.print("seqs: ");
            for(String seq:seqs){
                matchCnt+= trieCnt.searchCnt(seq);
                //System.out.print(seq+" ");
            }//System.out.println();

            ans.add(matchCnt);
        }


        return  ans;
    }

    public static void main(String[] args){

//        minimizeString("mukul");

//        String[] words = {"mf","abc", "efd"};
//        String[] puzzles = {"abcde","dabc"};

//        String[] words = {"aaaa","asas","able","ability","actt","actor","access"},
//                puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};

        String[] words = {"apple","pleas","please"},
                puzzles = {"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"};

        List<Integer> ans = findNumOfValidWords(words, puzzles);
        for(int x: ans){
            System.out.print(x+" ");
        }System.out.println();
    }



}
