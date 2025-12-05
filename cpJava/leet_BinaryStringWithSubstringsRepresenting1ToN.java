package offl.contest;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class leet_BinaryStringWithSubstringsRepresenting1ToN {

    static class SuffixAutomaton {

        private static class State {
            int length;
            int link;
            Map<Character, Integer> next;

            State() {
                length = 0;
                link = -1;
                next = new HashMap<>();
            }
        }

        private final List<State> st;
        private int last;

        public SuffixAutomaton(String s) {
            st = new ArrayList<>();
            st.add(new State());
            last = 0;
            for (char c : s.toCharArray()) {
                extend(c);
            }
        }

        private void extend(char c) {
            int cur = st.size();
            st.add(new State());
            st.get(cur).length = st.get(last).length + 1;

            int p = last;
            while (p != -1 && !st.get(p).next.containsKey(c)) {
                st.get(p).next.put(c, cur);
                p = st.get(p).link;
            }

            if (p == -1) {
                st.get(cur).link = 0;
            } else {
                int q = st.get(p).next.get(c);
                if (st.get(p).length + 1 == st.get(q).length) {
                    st.get(cur).link = q;
                } else {
                    int clone = st.size();
                    st.add(new State());
                    st.get(clone).length = st.get(p).length + 1;
                    st.get(clone).next.putAll(st.get(q).next);
                    st.get(clone).link = st.get(q).link;

                    while (p != -1 && st.get(p).next.get(c) == q) {
                        st.get(p).next.put(c, clone);
                        p = st.get(p).link;
                    }

                    st.get(q).link = clone;
                    st.get(cur).link = clone;
                }
            }
            last = cur;
        }

        public boolean contains(String pattern) {
            int cur = 0;
            for (char c : pattern.toCharArray()) {
                Integer nxt = st.get(cur).next.get(c);
                if (nxt == null) return false;
                cur = nxt;
            }
            return true;
        }


    }

    public static boolean queryString(String s, int n) {

        SuffixAutomaton sa = new SuffixAutomaton(s);

        for(int i=1; i<= n; i++){
            String str = Integer.toBinaryString(i);
            System.out.println("str:"+str);
            if(!sa.contains(str)){
                return false;
            }
        }
        return true;
    }


    public static void main(String[] args){

        String s = "0110";
        int n = 3;

        System.out.println(queryString(s,n));
    }
}
