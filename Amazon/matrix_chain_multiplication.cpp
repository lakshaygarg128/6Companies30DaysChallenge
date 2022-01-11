// TLE BY THIS METHOD
class Solution{
   
    
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<pair<int,string>>> dp(n,vector<pair<int,string>>(n));

         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = {-1,""};
            }
        }
        return helper(p,1,n-1,dp).second;
        
    }
    
    pair<int,string> helper(int p[],int i ,int  j, vector<vector<pair<int,string>>> &dp ){
        if(dp[i][j].first!=-1) return dp[i][j];
        char ans1='A'+i-1;
        string s(1,ans1);
        if(i>=j)return dp[i][j]={0,s};
        
        string ans="";
        int temp_ans,min_ans=INT_MAX;
        
        for(int k=i; k<=j-1;k++){
            
            pair<int,string> first_part = helper(p,i,k,dp);
            pair<int,string> second_part = helper(p,k+1,j,dp);
            
            temp_ans = first_part.first+ second_part.first+(p[i-1]*p[k]*p[j]);
            
            
            if(min_ans>temp_ans){
                min_ans=temp_ans;
                string check="A"+1;
                cout<<check;
                ans="("+first_part.second+second_part.second+")";
            }
        }
        
        return {min_ans,ans};
    }
};


// correct Method
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    pair<string,int> getMinOperations(int p[], string s, int i, int j, vector<vector<pair<string,int>>> &dp){
        if(dp[i][j].second != -1) return dp[i][j];
        if( i == j){
            dp[i][j] = {s.substr(i,1),0};
            return dp[i][j];
        }
        int product = INT_MAX;
        string q = "";
        for(int k=i;k<j;k++){
            pair<string,int> x = getMinOperations(p,s,i,k,dp);
            pair<string,int> y = getMinOperations(p,s,k+1,j,dp);
            string r = "";
            r.push_back('(');
            r += x.first + y.first;
            r.push_back(')');
            if(x.second+y.second + p[i]*p[k+1]*p[j+1] < product){
                product = x.second+y.second + p[i]*p[k+1]*p[j+1];
                q = r;
            }
        }
        dp[i][j] = {q,product};
        return dp[i][j];
        
    }
    string matrixChainOrder(int p[], int n){
        // code here
        string s = "",r="";
        for(int i=0;i<n-1;i++){
            s.push_back(char('A' + i));
        }
        vector<vector<pair<string,int>>> dp(n-1,vector<pair<string,int>>(n-1));
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                dp[i][j] = {r,-1};
            }
        }
        pair<string,int> ans = getMinOperations(p,s,0,s.length()-1,dp);
        // cout<<ans.second<<endl;
        return ans.first;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends