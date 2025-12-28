package offl.contest;

import java.util.HashSet;

public class leet_SmallestAllOnesMultiple {

    public int minAllOneMultiple(int k) {

        HashSet<Integer> remStore = new HashSet<>();

        int mul = 0;
        int cnt = 0;

        while(true){
            cnt++;
            mul = mul*10+1;
            mul %= k;

            if(mul == 0) break;
            if(remStore.contains(mul)) return -1;

            remStore.add(mul);

        }

        return cnt;
    }

}
