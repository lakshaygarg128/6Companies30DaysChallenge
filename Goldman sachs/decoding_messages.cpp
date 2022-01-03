
//TLE Recursion
class Solution {
	public:
		int CountWays(string str){
		    return helper(str,0);
		}
		int helper(string str, int i){
		    int n = str.size();
		    if(i>=n) return 1;
		    if(str[i]=='0') return 0;
		    if(str[i]>='3'){
		        return helper(str,i+1);
		    }
		    
		    if(str[i]=='1' and i+1<n ){
		        return helper(str,i+1)+helper(str,i+2);
		    }
		    if(i+1<n and str[i]=='2' and str[i+1]<='6'){
		        return helper(str,i+1)+helper(str,i+2);
		    }
		    if(i+1<n and str[i+1]=='0') return 0;
		    return helper(str,i+1);
		}

};

// DP 
class Solution {
	public:
	 const int MOD = 1000000007;
		int CountWays(string str){
		    vector<int> dp(str.size(),-1);
		    return helper(str,0,dp);
		}
		int helper(string str, int i,vector<int> &dp){
		  int n = str.size();
		    if(i>=n) return 1;
		    if(str[i]=='0') return dp[i]=0;
		    if(dp[i]!=-1) return dp[i];
            int res = helper(str,i+1,dp);
		    
		    if(str[i]=='1' and i+1<n){
		        res= (res+helper(str,i+2,dp))%MOD;
		    }
		    if(i+1<n and str[i]=='2' and str[i+1]<='6'){
		         res=(res+helper(str,i+2,dp))%MOD;
		    }
		   
		    return dp[i]=res;
		}

};