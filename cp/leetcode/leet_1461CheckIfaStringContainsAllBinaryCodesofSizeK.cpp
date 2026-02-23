class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        int requiredCount = 1 << k;

        std::unordered_set<int> foundCodes;
        int currentHash = 0;

        int mask = requiredCount - 1;

        for (int i = 0; i < s.length(); ++i) {
            currentHash = ((currentHash << 1) & mask) | (s[i] - '0');
            if (i >= k-1) {
                foundCodes.insert(currentHash);
            }

            if (foundCodes.size() == requiredCount) {
                return true;
            }
        }
        return false;
    }
};