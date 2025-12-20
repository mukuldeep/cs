package offl.contestLeetBW172;

public class leetBw172_Q4 {

    public static long lastRemaining(long n) {
        long head=1;
        long step=1;
        long remaining=n;
        boolean left=true;
        while(remaining>1){
            if (!left && remaining%2==0){
                head = head+step;
            }
            remaining = (remaining+1)/2;
            step=step*2;
            left=!left;
        }
        return head;
    }

    public static void main(String[] args){

        int target = 1;
        long ans = lastRemaining(target);
        System.out.println("Output: " + ans);
        //System.out.println("Output: " + Arrays.toString(ans));

        System.out.println();
    }
}
