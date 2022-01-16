class Solution{
public:
    int equalPartition(int n, int arr[])
    {
       
       int sum = 0;
       for(int i =0;i<n;i++) sum+=arr[i];
       if(sum%2!=0) return 0;
       sum=sum/2;
       vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
       for(int i = 0; i <= n ; i++ ){
           for(int j=0;j<=sum;j++){
               if(i==0 and j==0) {
                   dp[i][j]=0;
                   continue;
               }
               if(i==0){
                   dp[i][j]=0;
                   continue;
               }
               if(j==0){
                   dp[i][j]=1;
                   continue;
               }
               
               if(j>=arr[i-1]){
                   dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1]]);
               }else
               dp[i][j]=dp[i-1][j];
               
               
           }
       }
       return dp[n][sum];
    }
};