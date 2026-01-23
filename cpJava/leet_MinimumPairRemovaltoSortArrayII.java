class Solution {

   private static class P {
        long sum;
        int idx;
        P(long sum,int idx){
            this.sum=sum;
            this.idx=idx;
        }
    }

    public int minimumPairRemoval(int[] nums){
        int n=nums.length;
        if(n<=1) return 0;

        long[] arr=new long[n];
        for(int i=0; i<n;i++){
			arr[i]=nums[i];
		}

        int[] prev=new int[n];
        int[] next=new int[n];
        boolean[] removed=new boolean[n];

        PriorityQueue<P> pq=new PriorityQueue<>((a, b) -> {
            if(a.sum!=b.sum) return Long.compare(a.sum, b.sum);
            return Integer.compare(a.idx, b.idx);
        });

        int sortedCount=0;
        int currentSize=n;

        for(int i=0;i<n;i++){
            prev[i]=i-1;
            next[i]=i+1;
            if(i<n-1){
                pq.add(new P(arr[i]+arr[i+1], i));
                if(arr[i] <= arr[i+1]) sortedCount++;
            }
        }

        if(sortedCount == n-1) return 0;

        while(currentSize>1 && !pq.isEmpty()){
            P top=pq.poll();
            int left=top.idx;
            int right=next[left];

            if(right>=n || removed[left] || removed[right]) continue;
            if(arr[left]+arr[right]!=top.sum) continue;

            int p=prev[left];
            int nn=next[right];

            if(isSorted(p, left, arr)) sortedCount--;
            if(isSorted(left, right, arr)) sortedCount--;
            if(isSorted(right, nn, arr)) sortedCount--;

            arr[left]+=arr[right];
            removed[right]=true;
            
            next[left]=nn;
            if(nn<n) prev[nn]=left;
            
            currentSize--;

            if(isSorted(p, left, arr)) sortedCount++;
            if(isSorted(left, nn, arr)) sortedCount++;

            if(sortedCount == currentSize-1) return n-currentSize;

            if(p!=-1){
                pq.add(new P(arr[p]+arr[left], p));
            }
            if(nn!=n){
                pq.add(new P(arr[left]+arr[nn], left));
            }
        }

        return n-1;
    }

    private boolean isSorted(int i, int j, long[] arr){
        if(i<0 || j>=arr.length) return false;
        return arr[i] <= arr[j];
    }
}