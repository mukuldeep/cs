package offl.leetcodes;

import java.util.Arrays;

public class leet_GreatestSumDivisiblebyThree {

    public int maxSumDivThree(int[] nums) {
        int _2 = 0;
        int _1 = 0;
        int[] _2s = {100_000,100_000,100_000};
        int[] _1s = {100_000,100_000,100_000};
        int sm = 0;

        for(int num:nums){
            sm+=num;
            switch(num%3){
                case 1:
                    _1++;
                    _1s[2] = num;
                    Arrays.sort(_1s);
                    break;
                case 2:
                    _2++;
                    _2s[2] = num;
                    Arrays.sort(_2s);
                    break;
            }
        }

        switch (sm%3){
            case 0:
                return sm;
            case 1:
                if(_2>1 && (_1s[0] > (_2s[0]+_2s[1]))){
                    return sm - (_2s[0]+_2s[1]);
                }
                return sm - _1s[0];
        }

        if(_1>1 && (_2s[0] > (_1s[0]+_1s[1]))){
            return sm - (_1s[0]+_1s[1]);
        }
        return sm - _2s[0];
    }


}
