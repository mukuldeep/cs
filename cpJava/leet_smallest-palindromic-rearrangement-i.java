class Solution {

    public String smallestPalindrome(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            cnt[c-'a']++;
        }

        StringBuilder half = new StringBuilder();
        String mid = "";

        for(int i=0; i<26; i++){
            char ch = (char)(i+'a');
            if(cnt[i] % 2 ==1){
                mid = String.valueOf(ch);
                cnt[i]--;
            }
            int total_h_2  = cnt[i]>>1;
            for(int h = 0; h < total_h_2;h++){
                half.append(ch);
            }
        }

        return half.toString() + mid + half.reverse().toString();
    }

}