package offl.contest;

public class leet_NumberofEffectiveSubsequences {

    static int MOD = 1_000_000_007;

    static class SOS_DP {



        int MLOG;// = 20;
        int MAXN;// = (1 << MLOG);

        public SOS_DP(int MLOG){
            this.MLOG = MLOG;
            this.MAXN = (1<<MLOG);
        }

        //forward 1
        // count no of elements that are sub-mask of this number/mask
        public void noOfSubMaskForAll(int[] dp) {
            for (int bit = 0; bit < MLOG; bit++) {
                for (int i = 0; i < MAXN; i++) {
                    if ((i & (1 << bit)) > 0) {
                        dp[i] = (dp[i] + dp[i ^ (1 << bit)]) % MOD;
                    }
                }
            }
        }

        //backward 1
        // remove count of sub-mask that are not same as this mask/number
        public void excludeNoOfSubMaskDifferentThanIt(int[] dp) {
            for (int bit = 0; bit < MLOG; bit++) {
                for (int i =  MAXN - 1; i >= 0; i--) {
                    if ((i & (1 << bit)) > 0) {
                        dp[i] = ((dp[i] - dp[i ^ (1 << bit)]+MOD)%MOD) ;
                    }
                }
            }
        }

    }

    public static int countEffective(int[] nums) {

        int or_ = 0;
        for(int num: nums){
            or_ |= num;
        }

        int nBits = 0;
        int orC = or_;
        while (orC>0){
            nBits++;
            orC>>=1;
        }

        if((1<<nBits) < or_){
            nBits++;
        }

        SOS_DP sos_dp = new SOS_DP(nBits);

        int [] freq = new int[(1<<nBits)];
        for(int num:nums){
            freq[num]++;
        }

        //sos
        sos_dp.noOfSubMaskForAll(freq);

        int[] pow_2_mod = new int[nums.length+7];
        pow_2_mod[0]=1;
        for(int i=1;i<pow_2_mod.length;i++){
            pow_2_mod[i] = (pow_2_mod[i-1]<<1)%MOD;
        }

        //update with all non empty subsets
        for(int i=0;i<freq.length;i++){
            System.out.println(i+"-> "+freq[i]);
            freq[i] = pow_2_mod[(int)freq[i]]-1;//(1<<freq[i])-1;
        }

        System.out.println("_________________");

        for(int i=0; i<freq.length;i++){
            System.out.println(i+"-> "+freq[i]);
        }
        System.out.println("_________________");


        //Exclusion SOS
        sos_dp.excludeNoOfSubMaskDifferentThanIt(freq);

        int ans = 1;

        for(int i=0; i<freq.length;i++){
            System.out.println(i+"-> "+freq[i]);
        }

        for(int i=0; i<or_;i++){
            ans+= freq[i];
        }

        return ans;
    }

    public static void main(String[] args){

        //int[] arr = {1,2,3};

        int[] arr = {7,4,6};


        System.out.println(countEffective(arr));


//        SOS_DP_DEMO.SOS_DP sos_dp = new SOS_DP_DEMO.SOS_DP(4l);
//
//        int [] freq = new int[(1<<4)];
//        for(int ar:arr){
//            freq[(int)ar]++;
//        }
//
//        sos_dp.noOfSubMaskForAll(freq);
//        for(int i=0; i<freq.length;i++){
//            System.out.println(i+"-> "+freq[i]);
//        }
//        System.out.println("____________________");
//
//        sos_dp.excludeNoOfSubMaskDifferentThanIt(freq);
//        for(int i=0; i<freq.length;i++){
//            System.out.println(i+"-> "+freq[i]);
//        }
        System.out.println();


    }

}
