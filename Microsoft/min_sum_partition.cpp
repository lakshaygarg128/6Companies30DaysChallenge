class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	  int sum = 0;
	  for(int i = 0 ;i< n;i++){
	      sum+=arr[i];
	  }
	  
	  int  dp[n+1][sum+1];
	  
	  for(int i=0;i<=n;i++){
	      for(int j=0;j<=sum;j++){
	          if(i==0 and j!=0){
	              dp[i][j]=0;
	              continue;
	          }
	          if(j==0){
	            dp[i][j]=1;
	            continue;
	          } 
	          
	          if(arr[i-1]<=j){
	              dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i-1]];
	          }else{
	              dp[i][j]=dp[i-1][j];
	          }
	          
	      }
	  }
	  //cout<<dp[n][1]<<" "<<dp[n][4]<<"\n";
	  int ans;
	  for(int i =0;i<=sum/2;i++){
	      if(dp[n][i]){
	       //   cout<<i<<" ";
	          ans=abs(i-(sum-i));
	      }
	  }
	  
	  return ans;
	} 
};