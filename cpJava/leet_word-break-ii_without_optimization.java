class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashSet<String> wordInDict = new HashSet<>();

        for(String word: wordDict){
            wordInDict.add(word);
        }

        List<String> sentencesList = new ArrayList<>();
        sentences(0,"","",s,wordInDict,sentencesList)
        return sentencesList;

    }

    private void sentences(int i, String currWord,String currSentence, String s, HashSet<String> wordInDict,List<String> sentencesList){
        if(i>= s.length()){
            return;
        }

        currWord = currWord+String.valueOf(s.charAt(i));

        if(wordInDict.contains(currWord)){
            //word end at this position
            String space = currSentence == ""?"":" ";
             sentences(i+1,"",currSentence+space+currWord,s,wordInDict,sentencesList);
             if(i==s.length()-1){
                sentencesList.add(currSentence+space+currWord);
             }
        }
        //word doesnot end at this position
        sentences(i+1, currWord, currSentence, s, wordInDict,sentencesList);

    }




}