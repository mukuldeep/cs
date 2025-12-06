package offl.contest;


public class leet_MaximumXORofSubsequences {
    public class XorBasis {

        private static final int MAX_BITS = 62;  // Supports up to 2^62
        private long[] basis = new long[MAX_BITS]; // basis[i] -> vector with MSB i
        private int size = 0;  // number of basis vectors

        // --------------------------------------------------------------
        // Insert a number into the basis
        // --------------------------------------------------------------
        public void insert(long x) {
            long v = x;
            for (int i = MAX_BITS - 1; i >= 0; i--) {
                if (((v >> i) & 1) == 0) continue;

                if (basis[i] == 0) {
                    basis[i] = v;
                    size++;
                    return;
                }
                v ^= basis[i];
            }
        }


        // --------------------------------------------------------------
        // Maximum XOR obtainable from the basis
        // --------------------------------------------------------------
        public long getMaxXor() {
            long res = 0;
            for (int i = MAX_BITS - 1; i >= 0; i--) {
                if ((res ^ basis[i]) > res) {
                    res ^= basis[i];
                }
            }
            return res;
        }



        // --------------------------------------------------------------
        // Get basis size
        // --------------------------------------------------------------
        public int size() {
            return size;
        }

    }


    public int maxXorSubsequences(int[] nums) {
        XorBasis xorBasis = new XorBasis();
        for(int num: nums){
            xorBasis.insert(num);
        }
        return (int) xorBasis.getMaxXor();

    }


        public static void main(String[] args){
            long num1 = 42;

            int[] nums = {2, 7, 11, 15};
            int target = 9;


            System.out.println();
        }
}
