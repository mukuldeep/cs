package offl.leetcodes;

public class leet_LongestPalindromicSubstring {

    class ManacherUtils {
        private final String s;
        private final int[] p; // palindrome radii array
        private final String t; // transformed string with separators

        public ManacherUtils(String str) {
            this.s = str;
            this.t = preprocess(str);
            this.p = new int[t.length()];
            compute();
        }

        // Preprocess the string: "abba" -> "^#a#b#b#a#$"
        private String preprocess(String s) {
            StringBuilder sb = new StringBuilder("^");
            for (char c : s.toCharArray()) {
                sb.append('#').append(c);
            }
            sb.append("#$");
            return sb.toString();
        }

        // Core Manacher computation in O(n)
        private void compute() {
            int center = 0, right = 0;
            for (int i = 1; i < t.length() - 1; i++) {
                int mirror = 2 * center - i;
                if (i < right) {
                    p[i] = Math.min(right - i, p[mirror]);
                }

                // expand around center i
                while (t.charAt(i + (1 + p[i])) == t.charAt(i - (1 + p[i]))) {
                    p[i]++;
                }

                // update center and right boundary
                if (i + p[i] > right) {
                    center = i;
                    right = i + p[i];
                }
            }
        }

        // Returns the longest palindromic substring
        public String getLongestPalindrome() {
            int maxLen = 0, centerIndex = 0;
            for (int i = 1; i < p.length - 1; i++) {
                if (p[i] > maxLen) {
                    maxLen = p[i];
                    centerIndex = i;
                }
            }
            int start = (centerIndex - 1 - maxLen) / 2;
            return s.substring(start, start + maxLen);
        }

        // Returns palindrome radius array (optional)
        public int[] getRadiusArray() {
            return p;
        }

        // Returns length of longest palindrome
        public int getLongestPalindromeLength() {
            int max = 0;
            for (int v : p) max = Math.max(max, v);
            return max;
        }

        // Returns whether s[l..r] (inclusive) is palindrome in O(1)
        public boolean isPalindrome(int l, int r) {
            int len = r - l + 1;
            int center = l + r + 1; // mapped in transformed string
            int i = center + 1;     // because of '^' at start
            return p[i] >= len;
        }
    }




    public String longestPalindrome(String s) {
        ManacherUtils manacherUtils = new ManacherUtils(s);
        return manacherUtils.getLongestPalindrome();
    }
}
