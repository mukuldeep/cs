class Solution {

int firstEventStartingAfterX(int[][] events, int x){
    int target = x+1;;
    int l=0, h=events.length-1;
    int ans = events.length;

    while(l<=h){
        int mid = l+(h-l)/2;
        if (events[mid][0]>=target){
            ans = mid;
            h = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

    public int maxTwoEvents(int[][] events) {

        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        int[] _1Mx = new int[events.length+1];

        _1Mx[events.length] = 0;

        for(int i=events.length-1; i>=0; i--){
            _1Mx[i] = Math.max(_1Mx[i+1], events[i][2]);
        }

        int ans = events[0][2];

        for(int i=0;i<events.length;i++){
            int nextInd = firstEventStartingAfterX(events,events[i][1]);
            ans = Math.max(ans, events[i][2]+_1Mx[nextInd]);
        }

        return ans;
    }
}