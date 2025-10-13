class Solution {

 void computeLPS(String pat, int[] lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < pat.length()) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
    }

    List<Integer> KMPSearch(String pat, String txt) {
        List<Integer> foundIndices = new ArrayList<>();
        int m = pat.length();
        int n = txt.length();
        int[] lps = new int[m];
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while (i < n) {
            if (pat.charAt(j) == txt.charAt(i)) { i++; j++; }
            if (j == m) {
                foundIndices.add((i-j));
                j = lps[j - 1];
            } else if (i < n && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return foundIndices;
    }

    List<Integer> KMPSearch2(String pat, String txt,List<Integer> aInS, int k) {
        List<Integer> beautifulIndices = new ArrayList<>();
        int a_pointer = 0;
        
        int m = pat.length();
        int n = txt.length();
        int[] lps = new int[m];
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while (i < n) {
            if (pat.charAt(j) == txt.charAt(i)) { i++; j++; }
            if (j == m) {
                //beautifulIndices.add((i-j));
                int bInd = i - j;
                while(a_pointer < aInS.size() && bInd-aInS.get(a_pointer) > k ){
                    a_pointer++;
                }
                
                while (a_pointer < aInS.size() && Math.abs(bInd-aInS.get(a_pointer)) <= k){
                    beautifulIndices.add(aInS.get(a_pointer));
                    a_pointer++;
                }

                if(a_pointer >= aInS.size()){
                    break;
                }
                
                j = lps[j - 1];
            } else if (i < n && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return beautifulIndices;
    }

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> aInS = KMPSearch(a,s);
        List<Integer> bInd = KMPSearch2(b,s,aInS, k);
        return bInd;
    }
}