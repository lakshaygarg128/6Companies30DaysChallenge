class Solution {
  public:
    int maxProfit(int k, int N, int prices[]) {
        
        int dp[500][2][201];
        
        for(int i=N-1;i>=0;i--){
            for(int trans=0;trans<=k;trans++)
            {
                if(i==N-1){
                    dp[i][0][trans]=0;
                    dp[i][1][trans]= trans>0 ? prices[i]:0;
                }else{
                    dp[i][0][trans]=max(-prices[i]+dp[i+1][1][trans],dp[i+1][0][trans]);
                    dp[i][1][trans]=max((trans>=1 ? prices[i]+dp[i+1][0][trans-1]:0),dp[i+1][1][trans]);
                }
            }
        }
        return dp[0][0][k];
    }
};
