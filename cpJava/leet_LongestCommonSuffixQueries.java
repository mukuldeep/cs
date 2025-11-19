package offl.leetcodes;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class leet_LongestCommonSuffixQueries {

    static class TrieCnt {
        static class Node {
            Node[] nxt = new Node[26];
            boolean end = false;
            int cnt = 0;
            int fInd=-1;
        }

        private Node root;// = new Node();


        public TrieCnt(){
            root = new Node();
        }

        public void insert(String s, int ind) {
            Node cur = root;
            if(cur.fInd == -1){
                cur.fInd = ind;
            }
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null) {
                    cur.nxt[idx] = new Node();
                    cur.nxt[idx].fInd = ind;
                }
                cur.cnt++;
                cur = cur.nxt[idx];

            }
            cur.end = true;
        }

        public int startsWithFirstInd(String s) { // prefix only
            Node cur = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (cur.nxt[idx] == null)
                    return cur.fInd;
                cur = cur.nxt[idx];
            }
            return cur.fInd;
        }


    }



    public static int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        HashMap<Integer, ArrayList<Integer>> hs = new HashMap<>();
        for(int i=0;i< wordsContainer.length; i++){
            ArrayList<Integer> indList;
            if(hs.containsKey(wordsContainer[i].length())){
                indList = hs.get(wordsContainer[i].length());
            }else{
                indList = new ArrayList<>();
            }
            indList.add(i);
            hs.put(wordsContainer[i].length(),indList);
        }

        TrieCnt trieCnt = new TrieCnt();

        ArrayList<Integer> szArr = new ArrayList<>(hs.keySet());
        Collections.sort(szArr);

        for(int sz: szArr){
            System.out.println("size= "+sz+" ");
            for(int i: hs.get(sz)){
                System.out.print(i+" ");

                StringBuilder str = new StringBuilder(wordsContainer[i]);
                str.reverse();
                trieCnt.insert(str.toString(),i);

            }System.out.println();
        }System.out.println();

        int[] ans = new int[wordsQuery.length];

        for(int i=0;i< wordsQuery.length;i++){
            StringBuilder str = new StringBuilder(wordsQuery[i]);
            str.reverse();
            ans[i] = trieCnt.startsWithFirstInd(str.toString());
        }

        return ans;
    }


    public static void main(String[] args) {
        //String[] wordsContainer = {"abcd","bcd","xbcd"},wordsQuery = {"cd","bcd","xyz"};//1 1 1

        //String[] wordsContainer = {"abcdefgh","poiuygh","ghghgh"}, wordsQuery = {"gh","acbfgh","acbfegh"};//2 0 2
        String[] wordsContainer = {"aabbeabedfbabecdda","ecadaafbeafcedfeeee","eddfebdfbdcaffac","bdecaadeddbaabefea","cbffbbcdfdcddbedfcb","aadfbdaebabba","debddcfddcbdcbabafbc","cfabaaedfdca","dfffeeceeddeeca","adbcdeeccdcdeacebcb"},
                wordsQuery = {"bcecddafeddeee","cdfadadfdaacfcdcfa","fffededbedc","ccdafaedcededfcefde","bdaccffadfefbafedbcf","aeadaffadfe","fcbddefeddfecfbbb","fabfceccab","aceaccfffdcbbfaa","fafcabaeaed"};

        int[] ans = stringIndices(wordsContainer,wordsQuery);
        for(int x: ans){
            System.out.print(x+" ");
        }System.out.println();

    }
}
