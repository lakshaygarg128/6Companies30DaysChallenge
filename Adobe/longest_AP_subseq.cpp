// Video sol : explained in P-2 
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int maxlen=0;
        for(int i=0;i<n;i++){
            int currval=nums[i];
            
            for(int j=0; j<i; j++) {
                int diff = currval-nums[j];
                
                if(dp[j].count(diff)>0){
                    dp[i][diff]=dp[j][diff]+1;
                }else{
                    dp[i][diff]=1;
                }
                
                maxlen=max(maxlen,dp[i][diff]);
                
            }
        }
        return maxlen+1;
    }
};

// Concised Solution

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(1001,0));
        int maxlen=0;
        for(int i=0;i<n;i++){
            int currval=nums[i];
            
            for(int j=0; j<i; j++) {
                int diff = currval-nums[j]+500;
                
               
                    dp[i][diff]=dp[j][diff]+1;
               
                maxlen=max(maxlen,dp[i][diff]);
                
            }
        }
        return maxlen+1;
    }
};