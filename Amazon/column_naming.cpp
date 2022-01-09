class Solution{
    public:
    string colName (long long int n)
    {
        string ans;
        while(n!=0){
        // making 0 index    
        n--;    
        // calculating string right ot left
        
        int rem= n%26;
        
        ans = string(1,'A'+rem)+ans;
          
            n=n/26;
        }
        return ans;
        
       
    }
};