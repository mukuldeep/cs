class Solution {

    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int id = -1;
    }

    private void insert(TrieNode root, String s, int id) {
        TrieNode curr = root;
        for (char c : s.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) curr.children[idx] = new TrieNode();
            curr = curr.children[idx];
        }
        curr.id = id;
    }

    

    public long minimumCost(String source, String target, String[] original, String[] changed, int[] cost) {
        int n = source.length();
        int m = original.length;

        Map<String, Integer> stringToId = new HashMap<>();
        int idCount = 0;
        for (String s : original) if (!stringToId.containsKey(s)) stringToId.put(s, idCount++);
        for (String s : changed) if (!stringToId.containsKey(s)) stringToId.put(s, idCount++);

        long[][] dist = new long[idCount][idCount];
        for (long[] row : dist) Arrays.fill(row, Long.MAX_VALUE / 2);
        for (int i = 0; i < idCount; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = stringToId.get(original[i]);
            int v = stringToId.get(changed[i]);
            dist[u][v] = Math.min(dist[u][v], (long) cost[i]);
        }


        for (int k = 0; k < idCount; k++) {
            for (int i = 0; i < idCount; i++) {
                if (dist[i][k] == Long.MAX_VALUE / 2) continue;
                for (int j = 0; j < idCount; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        TrieNode root = new TrieNode();
        for (String s : stringToId.keySet()) {
            insert(root, s, stringToId.get(s));
        }

        long[] dp = new long[n + 1];
        Arrays.fill(dp, Long.MAX_VALUE / 2);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == Long.MAX_VALUE / 2) continue;

            if (source.charAt(i) == target.charAt(i)) {
                dp[i + 1] = Math.min(dp[i + 1], dp[i]);
            }

            TrieNode currS = root;
            TrieNode currT = root;

            //search
            searchAndApply(i, source, target, root, dist, dp, n);

        }

        return dp[n] >= Long.MAX_VALUE / 2 ? -1 : dp[n];
    }

    private void searchAndApply(int start, String s, String t, TrieNode root, long[][] dist, long[] dp, int n) {
        TrieNode nodeS = root;
        List<int[]> matchesS = new ArrayList<>();

        for (int j = start; j < n; j++) {
            nodeS = nodeS.children[s.charAt(j) - 'a'];
            if (nodeS == null) break;
            if (nodeS.id != -1) {
                boolean matchT = true;
                TrieNode nodeT = root;
                for (int k = start; k <= j; k++) {
                    nodeT = nodeT.children[t.charAt(k) - 'a'];
                    if (nodeT == null) {
                        matchT = false;
                        break;
                    }
                }
                if (matchT && nodeT.id != -1) {
                    long cost = dist[nodeS.id][nodeT.id];
                    if (cost < Long.MAX_VALUE / 2) {
                        dp[j + 1] = Math.min(dp[j + 1], dp[start] + cost);
                    }
                }
            }
        }
    }
}