package offl.leetcodes;

import java.util.*;

public class leet_PartitionArrayIntoTwoArraysToMinimizeSumDifference {

    public static void generateAllPossibility(int[] nums, int curr, int mxInd, int usedSoFar, int sumSoFar, HashMap<Integer, HashSet<Integer>> mp){
        if(curr==mxInd){
            HashSet<Integer> mphsh;
            if(mp.containsKey(usedSoFar)){
                mphsh = mp.get(usedSoFar);
            }else{
                mphsh = new HashSet<>();
            }
            mphsh.add(sumSoFar);
            mp.put(usedSoFar, mphsh);

            return;
        }

        generateAllPossibility(nums,curr+1,mxInd,usedSoFar+1, sumSoFar+nums[curr],mp);
        generateAllPossibility(nums,curr+1,mxInd,usedSoFar, sumSoFar,mp);

    }

    public static int minimumDifference(int[] nums) {
        int ans = 0;
        int n = nums.length/2;

        int mn = Integer.MAX_VALUE;
        for(int x:nums){
            mn = Math.min(mn,x);
        }
        if(mn<0){
            mn=-mn;
        }else{
            mn=0;
        }

        int sum = 0;
        for(int i=0;i<nums.length; i++){
            nums[i]+=mn;
            sum+=nums[i];
        }



        HashMap<Integer, HashSet<Integer>> mp = new HashMap<>(), mp2 = new HashMap<>();

        //HashMap<Integer, ArrayList<Integer>> mpa = new HashMap<>();

        generateAllPossibility(nums,0,n,0,0,mp);

        for (int x: mp.keySet()) {
            System.out.print(x+":");
            HashSet<Integer> hsh = mp.get(x);
            for(int y:hsh){
                System.out.print(y+" ");
            }
            System.out.println();
        }

        generateAllPossibility(nums,n,2*n,0,0,mp2);
        HashMap<Integer, ArrayList<Integer>> mpa = new HashMap<>();
        for (int x: mp2.keySet()) {
            System.out.print(x+":");
            HashSet<Integer> hsh = mp2.get(x);
            ArrayList<Integer> arr = new ArrayList<>();
            for(int y:hsh){
                System.out.print(y+" ");
                arr.add(y);
            }
            System.out.println();
            Collections.sort(arr);
            mpa.put(x,arr);
        }

        //todo
        int mxSum = -1;
        int targetSum = sum/2;
        System.out.println("sum:"+sum+" targetsum:"+targetSum);

        for (int x: mp.keySet()) {
            System.out.print("checking for length "+ x + ":");
            HashSet<Integer> hsh = mp.get(x);
            ArrayList<Integer> lookupArr = mpa.get(n-x);
            System.out.print("\nlookup arr: ");for(int f:lookupArr){System.out.print(f+" ");}System.out.println();
            for (int y : hsh) {

                int pos = Collections.binarySearch(lookupArr,targetSum-y);
                if (pos < 0) pos = -pos - 1;

                if(pos<lookupArr.size() && (y+lookupArr.get(pos))<= targetSum ){
                    mxSum = Math.max(mxSum, y+lookupArr.get(pos));
                }
                pos--;
                if(0 <= pos && pos<lookupArr.size() && (y+lookupArr.get(pos))<= targetSum ){
                    mxSum = Math.max(mxSum, y+lookupArr.get(pos));
                }
            }
            System.out.println();
            System.out.println("mxSum:"+mxSum);
        }


        ans = Math.abs(sum-2*mxSum);


        return ans;
    }

    public static void main(String[] args){

        int[] nums = {-36,36};//{3,9,7,3};//{3,4,5,6,7,8};
        int ans =  minimumDifference(nums);
        System.out.println(ans);

    }

//    O(32000 * log(32000))
//    = O(32k * 15)
//    = O(2^15*15)
//    = O(2^19)
//    = O(512000) = O(5*1e5)

}
