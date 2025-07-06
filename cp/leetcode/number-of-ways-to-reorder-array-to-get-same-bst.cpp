#define ll long long
class Solution {
public:
    const static ll N=10005;
    ll factorialNumInverse[N + 1];
    ll naturalNumInverse[N + 1];
    ll fact[N + 1];
    void InverseofNumber(ll p)
    {
        naturalNumInverse[0] = naturalNumInverse[1] = 1;
        for (ll i = 2; i <= N; i++)
            naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
    }
    void InverseofFactorial(ll p)
    {
        factorialNumInverse[0] = factorialNumInverse[1] = 1;
        for (ll i = 2; i <= N; i++)
            factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
    }

    void factorial(ll p)
    {
        fact[0] = 1;
        for (ll i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % p;
        }
    }

    void pre(){
        ll p = 1000000007;
        InverseofNumber(p);
        InverseofFactorial(p);
        factorial(p);
    }

    ll nw(vector<int> nums,ll p = 1000000007){
        if(nums.empty())return 1;

        vector<int> left,right;
        for(ll i=1;i<nums.size();i++){
            if(nums[i]<nums[0])
                left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        ll lans=nw(left);
        ll rans=nw(right);
        ll ans=(fact[nums.size()-1]*factorialNumInverse[left.size()])%p;
        ans=(ans*factorialNumInverse[right.size()])%p;
        ans =(ans*lans)%p;
        ans=(ans*rans)%p;
        return ans;

    }
    int numOfWays(vector<int>& nums) {
        pre();
        return nw(nums)-1;
    }
};