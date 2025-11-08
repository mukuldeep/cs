package offl.leetcodes;

public class leet_SumOfScoresOfBuiltStrings {
    
    static long zFunction(String s) {
        int n = s.length();
        long ans = n;
        int[] z = new int[n];
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                z[i] = Math.min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
                z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }

            ans += z[i];
        }


        return ans;
    }


    public static long sumScores(String s) {
        long ans = 0;
        long z = zFunction(s);

//        for(int x:z) {
//            System.out.print(x + " ");
//        }System.out.println();

        return z;
    }


    public static void main(String[] args){
        String str = "azbazbzaz";//""babab";


        long ans = sumScores(str);

        System.out.println("ans= "+ans);

    }


}
