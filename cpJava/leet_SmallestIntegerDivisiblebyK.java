package offl.contest;

import java.util.Arrays;

public class leet_SmallestIntegerDivisiblebyK{

    public int smallestRepunitDivByK(int k) {
        if((k&1) == 0){
            return -1;
        }

        boolean[] pigeonHole = new boolean[k];
        // Arrays.fill(pigeonHole,false);
        pigeonHole[0] = true;

        int num = 0;
        for(int i=1;i<=k;i++){
            num=(num<<3)+(num<<1)+1;
            num%=k;

            if(pigeonHole[num]){
                if(num==0){
                    return i;
                }
                return -1;
            }
            pigeonHole[num] = true;
        }

        return -1;
    }


}
