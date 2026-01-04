package offl.contest;

import java.util.Arrays;

public class leet_FourDivisors {

    public int sumFourDivisorOp(int[] nums){

        int mx = 0;
        for(int num: nums){
            mx = Math.max(mx, num);
        }
        mx+=5;

        int[] divCnt = new int[mx];
        int[] divSum = new int[mx];
        Arrays.fill(divCnt,1);
        Arrays.fill(divSum,1);

        //preprocess
        for(int num = 2; num<mx; num++){
            for(int mult=num; mult<mx;mult+=num){
                divCnt[mult]++;
                divSum[mult]+=num;
            }
        }

        int ans = 0;
        for(int num: nums){
            if(divCnt[num]==4){
                ans += divSum[num];
            }
        }

        return ans;

    }


    public int sumFourDivisors(int[] nums) {
        int[] divCnt = new int[100_005];
        int[] divSum = new int[100_005];
        Arrays.fill(divCnt,1);
        Arrays.fill(divSum,1);

        //preprocess
        for(int num = 2; num<100_005; num++){
            for(int mult=num; mult<100_005;mult+=num){
                divCnt[mult]++;
                divSum[mult]+=num;
            }
        }

        int ans = 0;
        for(int num: nums){
            if(divCnt[num]==4){
                ans += divSum[num];
            }
        }

        return ans;

    }


    public static void main(String[] args){
        long num1 = 42;

        int[] nums = {2, 7, 11, 15};
        int target = 9;


        System.out.println();
    }
}
