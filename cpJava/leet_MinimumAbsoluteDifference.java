class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minDif = 100_000_000;
        for(int i=1;i<arr.length;i++){
            minDif = Math.min(minDif,arr[i]-arr[i-1]);
        }
        List<List<Integer>> ans = new ArrayList<>();

        for(int i=1;i<arr.length;i++){
            if(arr[i]-arr[i-1] == minDif){
                ans.add(List.of(arr[i - 1], arr[i]));
            }
        }
		
        return ans;
    }
}