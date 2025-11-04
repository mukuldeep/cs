package offl.leetcodes;

public class IncreasingTripletSubsequence {
    public boolean increasingTriplet(int[] nums) {
        int[] tails = new int[3];
        int size = 0;
        for (int ff:nums) {

            boolean updated = false;
            for(int i=0;i<size;i++){
                if(tails[i] >= ff){
                    tails[i] = ff;
                    updated = true;
                    break;
                }
            }

            if(!updated){
                size++;
                if(size >= 3){
                    return true;
                }
                tails[size-1] = ff;
            }

        }
        return false;
    }

}
