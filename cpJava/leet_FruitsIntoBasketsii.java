package offl.leetcodes;

public class leet_FruitsIntoBasketsii {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        boolean[] v = new boolean[baskets.length];
        int unplacedCnt = 0;
        for(int fruit: fruits){
            boolean isPlaced = false;
            for(int i=0;i<baskets.length;i++){
                if(!v[i] && baskets[i] >= fruit){
                    isPlaced = true;
                    v[i] = true;
                    break;
                }
            }
            if(!isPlaced){
                unplacedCnt++;
            }
        }

        return unplacedCnt;
    }
}
