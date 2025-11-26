package offl.contest;

import java.util.ArrayList;
import java.util.HashMap;

public class leet_NumberofWaystoPaintNx3Grid {
    static int MOD = 1_000_000_007;
    static void generateAllCombination(String colors, ArrayList<Integer> list, HashMap<Character,Integer> mp, int len, int lenSoFar, char lastCh, String colSoFar){
        if(lenSoFar == len){
            int num=0;
            for(char ch: colSoFar.toCharArray()){
                num<<=3;
                num|= mp.get(ch);
            }
            list.add(num);
            System.out.println(colSoFar+" "+Integer.toBinaryString(num));
            return;
        }
        for(char ch: colors.toCharArray()){
            if(ch != lastCh){
                generateAllCombination(colors, list, mp, len,lenSoFar+1,ch,colSoFar+ch);
            }
        }
    }

    static ArrayList<Integer> generateAllCombination(int len){
        ArrayList<Integer> list = new ArrayList<>();
        HashMap<Character,Integer> mp = new HashMap<>();
        mp.put('R',1);
        mp.put('G',2);
        mp.put('Y',4);
        generateAllCombination("RGY",list, mp, len,0,' ',"");

        return list;
    }


    public static int numOfWays(int n) {

        ArrayList<Integer> list = generateAllCombination(3);
        System.out.println("all Combination size = "+list.size());

        ArrayList<HashMap<Integer,Integer>> hms = new ArrayList<>();
        hms.add(new HashMap<>());
        hms.add(new HashMap<>());

        for(int i:list){
            hms.get(1).put(i,1);
        }

        for(int i=2;i<= n; i++){
            int prevHmInd = ((i&1)==1?0:1);
            int currHmInd = ((i&1)==1?1:0);

            //reset the current hm
            hms.get(currHmInd).clear();

            //calc answers for current states
            for(int xx: list){
                int currAns = 0;
                for(int yy: hms.get(prevHmInd).keySet()){
                    if((xx & yy)==0){
                        currAns+= hms.get(prevHmInd).get(yy);
                        currAns %= MOD;
                    }
                }
                hms.get(currHmInd).put(xx,currAns);
            }
        }



        int ans = 0;
        int ind = (n&1)==1?1:0;
        for(int yy: hms.get(ind).keySet()){
            ans += hms.get(ind).get(yy);
            ans %= MOD;;
        }

        return ans;
    }

    public static void main(String[] args) {
        int n = 5000;
        int ans = numOfWays(n);
        System.out.println(ans);


    }
}
