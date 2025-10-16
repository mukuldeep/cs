class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> wordInDict = new HashSet<>();

        int mxSize = 0;

        for(String word: wordDict){
            wordInDict.add(word);
            mxSize = Math.max(mxSize,word.length());
        }

        boolean[] isvalidSeg = new boolean[s.length()+1];

        //base case 0 lenth is valid
        isvalidSeg[0] = true;

        //dp table
        for(int i=1;i<=s.length();i++){
            for(int wordLen = 1;wordLen<= mxSize; wordLen++){
                if(i-wordLen < 0){
                    break;
                }
                if(isvalidSeg[i-wordLen] && wordInDict.contains(s.substring(i-wordLen,i))){
                    isvalidSeg[i] = true;
                } 
            }
        }


        return isvalidSeg[s.length()];
    }




}