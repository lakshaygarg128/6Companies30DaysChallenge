class Solution {
    
public:
    bool stoneGame(vector<int>& piles) {
        int sum=0,n=piles.size();
        for(auto x: piles){
            sum+=x;
        }
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(solve(0,n-1,piles,dp) >= sum/2) return true;
        return false;
        
    }
    int solve(int i,int j, vector<int> & piles,vector<vector<int>> &dp){
        if(i>j) return 0 ;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1 = piles[i] + min( solve(i+2,j,piles,dp) , solve(i+1,j-1,piles,dp));
        int op2 = piles[j] + min( solve(i+1,j-1,piles,dp) , solve(i,j-2,piles,dp));
        
        return dp[i][j]=max(op1,op2);
        
    }
};