class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        if(s.length()==1){
            return 0;
        }

        vector<int> a(n+1), b(n+1);

        b[0] = s[0]=='b'?1:0;
        for(int i=1;i<n;i++){
            b[i] = b[i-1]+(s[i]=='b'?1:0);
        }

        a[n-1] = s[n-1]=='a'?1:0;
        for(int i=n-2;i>=0;i--){
            a[i] = a[i+1]+(s[i]=='a'?1:0);
        }

        int minDel =  a[1];
        for(int i=1; i < n; i++){
            minDel = min(minDel, b[i-1]+a[i+1] );
        }
        return minDel;
    }
};