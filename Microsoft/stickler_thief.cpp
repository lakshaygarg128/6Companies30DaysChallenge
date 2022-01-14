class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int a[], int n)
    {
        if(n==1) return a[0];
        if(n==2) return max(a[0],a[1]);
        vector<int> dp(n,-1);
         dp[0]=a[0], dp[1]=a[1], dp[2] = a[0]+a[2];
        for(int i=3;i<n;i++){
            dp[i] = a[i] + max(dp[i-2],dp[i-3]);
        }
        return  max(dp[n-1],dp[n-2]);
        
    }
 
};