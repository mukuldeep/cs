package offl.leetcodes;

public class leet_FirstBadVersion {
    static int bad_version = 3475;
    boolean isBadVersion(int version){
        return version <= bad_version;
    }

    public int firstBadVersion(int n) {
        long r = n; //Integer.MAX_VALUE;
        long l = 0;

        while(l<r){
            long mid = (l+r)/2;
            if(isBadVersion((int)mid)){
                r = mid;
            }else{
                l = mid+1;
            }
            //System.out.println(l+" "+r);
        }

        return (int)l;
    }
}
