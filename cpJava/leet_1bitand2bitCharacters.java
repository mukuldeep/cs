package offl.leetcodes;

public class leet_1bitand2bitCharacters {
    public boolean isOneBitCharacter(int[] bits) {
        boolean isLast1 = false;
        for(int i=0;i<bits.length;){
            if(bits[i]==1){
                i+=2;
                isLast1 = false;
            }else{
                i++;
                isLast1 = true;
            }
        }

        return isLast1;
    }
}
