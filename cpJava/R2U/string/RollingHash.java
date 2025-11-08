package offl.string;

public class RollingHash {
    private static final long MOD = 1_000_000_007L; // large prime
    private static final long BASE = 131L;          // common base for hashing

    private final long[] prefixHash;  // prefixHash[i] = hash of s[0..i-1]
    private final long[] power;       // power[i] = BASE^i % MOD
    private final int n;

    /**
     * Precomputes prefix hashes and powers in O(n)
     */
    public RollingHash(String s) {
        n = s.length();
        prefixHash = new long[n + 1];
        power = new long[n + 1];
        power[0] = 1;

        for (int i = 0; i < n; i++) {
            prefixHash[i + 1] = (prefixHash[i] * BASE + s.charAt(i)) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }
    }

    /**
     * Returns hash of substring s[l..r] (inclusive)
     * O(1) time complexity
     */
    public long getHash(int l, int r) {
        if (l < 0 || r >= n || l > r) throw new IllegalArgumentException("Invalid range");
        long hash = (prefixHash[r + 1] - (prefixHash[l] * power[r - l + 1]) % MOD + MOD) % MOD;
        return hash;
    }

    /**
     * Returns length of the string used for hashing
     */
    public int length() {
        return n;
    }
}

