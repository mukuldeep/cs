class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        int ans = 0;

        int prevNotDeletedCol = -1;

        boolean[] isSorted = new boolean[strs.length];
        Arrays.fill(isSorted, false);

        for(int col=0; col<m;col++){

            boolean isDeleted = false;
            ArrayList<Integer> sorting = new ArrayList<>();
            for(int i=0;i<strs.length;i++){
                if(isSorted[i]){
                    continue;
                }

                char ch00 = ' '; char ch01 = ' ';
                char ch10 = ' '; char ch11 = strs[i].charAt(col);

                if(i>0){
                    ch01 = strs[i-1].charAt(col);
                    if(prevNotDeletedCol >= 0){
                        ch00 = strs[i-1].charAt(prevNotDeletedCol);
                    }
                }
                if(prevNotDeletedCol >= 0){
                    ch10 = strs[i].charAt(prevNotDeletedCol);
                }

                if(ch00 == ch10 && ch01 > ch11){
                    ans++;
                    isDeleted = true;
                    break;
                }else if(ch01 < ch11){
                    sorting.add(i);
                }
            }

            if(!isDeleted){
                prevNotDeletedCol = col;
                for(int x: sorting){
                    isSorted[x] = true;
                }
            }
        }

        return ans;
    }
}