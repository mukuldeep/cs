package offl.contestLeetBW173;

public class leetBw173_Q1 {

    public String reversePrefix(String s, int k) {

        if(s==null || k<=0){
            return s;
        }
        k=Math.min(k,s.length());
        String firstPart = new StringBuilder(s.substring(0,k)).reverse().toString();
        String remaining = s.substring(k);
        return firstPart+remaining;

    }


    public static void main(String[] args){
        System.out.println();
    }
}
