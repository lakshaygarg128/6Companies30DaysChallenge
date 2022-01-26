class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int>(b,1));
        
        for(int i = 1; i<a ;i++){
            for(int j = 1; j<b; j++){
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[a-1][b-1];
    }
};
