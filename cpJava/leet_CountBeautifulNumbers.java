package offl.contest;

import java.util.HashMap;

public class leet_CountBeautifulNumbers {

    static HashMap<String,Integer> hm;
    public static int solve(String num, int idx, int tight, int prod, int sum, int allPreZero){
        //base condition
        if(idx == num.length()){
            if(sum==0){
                return 0;
            }
            return (prod%sum==0)?1:0;
        }

        String key = idx+"_"+tight+"_"+prod+"_"+sum+"_"+allPreZero;
        //repeated subproblem
        if(hm.containsKey(key)){
            return hm.get(key);
        }



        int limit = (tight == 1) ? (num.charAt(idx)-'0'):9;
        int ans = 0;
        for(int i=0;i<= limit; i++){
            int d = num.charAt(idx)-'0';
            int updatedTight = ((tight==1)&&(i == d))? 1: 0;
            int updatedAllPreZero = ((allPreZero==1) && (i==0))?1:0;
            int updatedProd = prod * (updatedAllPreZero==1?1:i);
            int updatedSum = sum+i;

            ans += solve(num,idx+1,updatedTight,updatedProd,updatedSum,updatedAllPreZero);
        }

        hm.put(key,ans);
        return ans;
    }
    public static int beautifulNumbers(int l, int r) {
        hm = new HashMap<>();
        int left = solve(String.valueOf(l-1),0,1,1,0,1);
        hm.clear();
        int right = solve(String.valueOf(r),0,1,1,0,1);

        return right - left;

    }

    public static void main(String[] args) {

        //long num1 = 10;//262

        int l= 100,r=2000000;
        System.out.println(beautifulNumbers(l,r));


    }
}
