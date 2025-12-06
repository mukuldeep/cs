package offl.contestLeetBW171;


import java.util.Arrays;


public class leet_bw171_C {
    public static int[] fn(int[] nums, int target){

        return nums;
    }

    public long maxPoints(int[] technique1, int[] technique2, int k) {

        int[][] arr = new int[technique1.length][3];
        for (int i = 0; i<technique1.length; i++) {
            arr[i][0]=technique1[i];
            arr[i][1]=technique2[i];
            arr[i][2]=technique1[i]-technique2[i];
        }
        Arrays.sort(arr, (a, b) -> Integer.compare(b[2], a[2])); //by diff L2S
        int n=technique1.length;
        long ans=0;
        for (int i=0; i<k; i++){
            ans+=arr[i][0];
        }
        for (int i=k; i<n; i++){
            ans+=Math.max(arr[i][0],arr[i][1]);
        }
        return ans;

    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] ans = fn(nums, target);
        System.out.println("Output: " + Arrays.toString(ans));

        System.out.println();
    }
}
