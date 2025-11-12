package offl.leetcodes;

public class leet_MinimumNumberOfOperationsToMakeAllArrayElementsEqualTo1 {

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static int minOperations(int[] nums) {
        int gcdm = nums[0];
        int oneCnt = nums[0]==1?1:0;
        for(int i=1;i<nums.length;i++){
            gcdm = gcd(gcdm,nums[i]);
            if(nums[i]==1){
                oneCnt++;
            }
        }
        if(gcdm>1){
            return -1;
        }
        if(oneCnt>0){
            return nums.length - oneCnt;
        }

        int mnln = nums.length;
        for(int i=0; i< nums.length; i++){
            int gcdij = nums[i];
            for(int j=i+1; j<nums.length && ((j-i+1) <= mnln);j++){
                gcdij = gcd(gcdij,nums[j]);
                if(gcdij == 1){
                    mnln = Math.min(mnln,j-i+1);
                }
            }
        }

        return (nums.length + mnln - 2);
    }


    public static void main(String[] args){
        int[] nums = {2,10,6,14}; //{2,6,3,4};
        int ans = minOperations(nums);
        System.out.println(ans);

    }
}
