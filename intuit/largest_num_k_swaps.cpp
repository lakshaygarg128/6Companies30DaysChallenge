class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string &res,string str, int k, int indx){
        if(indx>=str.size()) return;
        int curr = str[indx]-'0';
        int n = str.size();
        if(k==0) return ;
        int next = curr;
        for(int i = indx+1; i < n; i++){
            int temp = str[i]-'0';
            next = max(temp,next);
        }
        
        if(next!=curr)k--;
        
        for(int i = n-1; i >= indx; i--){
            if(str[i]-'0'==next){
                
                swap(str[i],str[indx]);
                if(res < str){
                    res = str;
                }
                helper(res,str,k,indx+1);
                swap(str[i],str[indx]);
                
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string ans="";
       helper(ans,str,k,0);
       return ans;
    }
};