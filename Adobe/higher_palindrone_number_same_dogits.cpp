class Solution{
  public:
    string nextPalin(string N) { 
     
        int n = N.size();
        
        string ans;
        
        for(int i=0;i<n/2;i++){
            ans.push_back(N[i]);
        }
        
                if( next_permutation( ans.begin() , ans.end() ) ){
                string rev = ans;
                reverse(ans.begin(),ans.end());
                if(n%2!=0) rev.push_back(N[n/2]);
                ans = rev+ans;
                
                return ans;
                }
                return "-1";
    
    }
 
};
