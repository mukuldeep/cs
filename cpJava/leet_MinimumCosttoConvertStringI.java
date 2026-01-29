class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {

        long[][] dist = new long[26][26];
        long INF = 1_000_000_000_000L; 
        
        for (int i=0; i<26; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }
        

        for (int i = 0; i < original.length; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = Math.min(dist[u][v], (long) cost[i]);
        }

        for (int k=0; k<26; k++) {
            for (int i=0; i<26; i++) {
                if (dist[i][k]==INF) continue; 
                for (int j = 0; j < 26; j++) {
                    if (dist[k][j] < INF) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }


        long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int sChar = source.charAt(i) - 'a';
            int tChar = target.charAt(i) - 'a';
            
            if (sChar == tChar) continue;
            
            if (dist[sChar][tChar] >= INF) {
                return -1;
            }
            totalCost += dist[sChar][tChar];
        }

        return totalCost;
    }
}