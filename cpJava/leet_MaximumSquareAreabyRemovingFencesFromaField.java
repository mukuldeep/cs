package offl.contest;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class leet_MaximumSquareAreabyRemovingFencesFromaField {

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        int[] hF = new int[hFences.length+2];
        int[] vF = new int[vFences.length+2];

        for(int i=0;i<hFences.length;i++){
            hF[i] = hFences[i];
        }
        hF[hFences.length] = m;
        hF[hFences.length+1] = 1;

        for(int i=0;i<vFences.length;i++){
            vF[i] = vFences[i];
        }
        vF[vFences.length] = n;
        vF[vFences.length+1] = 1;

        Arrays.sort(hF);
        Arrays.sort(vF);

        HashSet<Long> hs = new HashSet<>();
        for(int i=0; i<hF.length;i++){
            for(int j = i+1; j<hF.length; j++){
                hs.add((long) Math.abs(hF[i] - hF[j]));
            }
        }


        long ans = -1;
        for(int i=0; i<vF.length;i++){
            for(int j = i+1; j<vF.length; j++){
                long currDiff = Math.abs(vF[i] - vF[j]);
                if(hs.contains(currDiff)){
                    ans = Math.max(ans,currDiff*currDiff);
                }
            }
        }

        if(ans==-1){
            return -1;
        }

        ans %= 1_000_000_007;
        return (int)ans;
    }

}
