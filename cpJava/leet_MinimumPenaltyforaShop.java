class Solution {

    static final int[] MAP = new int[128];
    static {
        MAP['Y'] = -1;
        MAP['N'] = 1;
    }

    static int mapChar(char c) {
        return MAP[c];
    }

    static final int[] MAP2 = new int[128];
    static {
        MAP2['Y'] = 1;
        MAP2['N'] = 0;
    }

    static int mapChar2(char c) {
        return MAP2[c];
    }


    public int bestClosingTime(String customers) {
        int nys = 0;
        for(char ch:customers.toCharArray()){
                nys+=mapChar2(ch);            
        }
        if(nys == 0){
            return 0;
        }

        int scr = 0;
        int mnScore = nys;
        int ans = 0;

        for(int i=0;i<customers.length();i++){
            scr += mapChar(customers.charAt(i));
            if(mnScore > nys + scr){
                mnScore = nys + scr;
                ans = i+1;
            }
        }
        return ans;
        
    }
}