package offl.leetcodes;

import java.util.ArrayList;

public class leet_MyCalendari {

    public class Pair<U, V> {
        public final U first;
        public final V second;

        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }
    }


    //vector<Pair<int, int>> ranges;

    ArrayList<Pair<Integer,Integer>> ranges;

    public leet_MyCalendari() {
        ranges = new ArrayList<>();
    }

    boolean book(int start, int end) {
        for (Pair<Integer,Integer> pair : ranges) {
            if ( pair.first < end &&  start < pair.second)
                return false;
        }
        ranges.add(new Pair<>(start, end));
        return true;
    }
}
