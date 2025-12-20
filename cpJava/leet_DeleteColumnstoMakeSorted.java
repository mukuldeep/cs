class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        boolean[] isDeleted = new  boolean[m];
        Arrays.fill(isDeleted,false);

        for(int j=0;j<m;j++){
            for(int i=1;i<strs.length;i++){
                if(strs[i-1].charAt(j) > strs[i].charAt(j)){
                    isDeleted[j] = true;
                    break;
                }
            }
        }

        m = 0;
        for(boolean isDel: isDeleted){
            m+= (isDel?1:0);
        }

        return m;
    }

}