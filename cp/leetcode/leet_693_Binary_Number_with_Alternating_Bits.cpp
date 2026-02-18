class Solution {
public:
    // bool hasAlternatingBitsLoop(int n) {
    //     bool bt = n&1;
    //     while(n>0){
    //         if((n&1) != bt){
    //             return false;
    //         }
    //         n>>=1;
    //         bt=!bt;
    //     }
    //     return true;
    // }

    // bool hasAlternatingBits(int n) { // Bitmask
    //     int oddMask = 0x55555555 & n;
    //     int evenMask = 0xaaaaaaaa & n;

    //     if(oddMask>0 && evenMask > 0){
    //         return false;
    //     }
    //     long ln = n;
    //     if(__builtin_popcount((ln|(ln>>1))+1)!=1){
    //         return false;
    //     }
    //     return true;
    // }

    bool hasAlternatingBits(int n) {
        long ln = n;
        return !((0x55555555 & n) && (0xaaaaaaaa & n)) && !(__builtin_popcount((ln|(ln>>1))+1)!=1);
    }
};