package offl.leetcodes;

public class leet_CheckIfAll1sAreatLeastLengthKPlacesAway {

    public boolean kLengthApart(int[] nums, int k) {

        int last1ind = -k-5;
        for(int i = 0; i<nums.length; i++){
            if((nums[i]&1)==1){
                if(i-last1ind-1<k){
                    return false;
                }
                last1ind = i;
            }
        }
        return true;
    }


}
