package offl.contest;

public class leet_MaximumRunningTimeofNComputers {

    public static boolean isPossibleBatteryHours(int n, int[] batteries, long hours){
        long reqBH = (long)n * (long)hours;
        long availBH = 0;
        for(int b:batteries){
            availBH += Math.min(b, hours);
        }
        return reqBH<=availBH;
    }


    public static long maxRunTime(int n, int[] batteries) {
        long sum = 0;
        for(int b: batteries){
            sum += b;
        }
        long l = 0;
        long r = (sum/n)+5;
        while(l<r){
            long mid = (long)Math.ceil((l+r)/2.0);
            boolean isvalid = isPossibleBatteryHours(n,batteries,mid);
            //System.out.println("l="+l+" m="+mid+" r="+r+" isValid="+isvalid);
            if(isvalid){
                l=mid;
            }else{
                r = mid-1;
            }
        }
        return l;
    }

    public static void main(String[] args){
//        int n = 2;
//        int[] batteries = {3,3,3};

        int n = 2;
        int[] batteries = {1,1,1,1};

        System.out.println(maxRunTime(n,batteries));
    }
}
