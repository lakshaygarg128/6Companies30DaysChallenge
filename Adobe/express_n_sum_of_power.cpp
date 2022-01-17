class Solution{
    public:
    long long   numOfWays(long long  n, int x)
    {
        vector<vector<long long >> dp(pow(n,1.0/x)+1,vector<long long >(n+1,-1));
        helper(pow(n,1.0/x),n,x,dp);
        return dp[pow(n,1.0/x)][n];
    }
    
    long long  helper(long long i, long long n ,long long x ,vector<vector<long long >> &dp){
        if(n==0) {
            return 1;
        }
        if(i==0) return 0;
       long long &ans = dp[i][n];
        if(ans != -1) return ans;
        long long power = pow(i, x);
        return ans = (n - power >= 0 ? helper(i - 1,n - power, x,  dp): 0) + helper(i-1,n, x,dp);
        
    }
};