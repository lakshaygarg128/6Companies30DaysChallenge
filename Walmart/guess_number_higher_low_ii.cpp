class Solution {
    vector<vector<int>> dp;
public:
    int getMoneyAmount(int n) {
        
        for(int i = 0 ;i <= n ; i++ ) {
            vector<int> temp ;
            for(int j = 0; j <= n ; j++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
        return helper(1,n);
    }
    
    int  helper(int i, int j){
        
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k <= j ; k++) {
            int l = k + helper(i,k-1);
            int r = k + helper(k+1,j);
            ans = min(ans, max(l,r));
        }
        
        return dp[i][j] = ans;
    }
};