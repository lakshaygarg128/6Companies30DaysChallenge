class Solution {
public:
    void helper(int  i,int dig[],int n , string out,vector<string> &ans,string arr[]){
        if(i==n){
            ans.push_back(out);
            return;
        }
        
        
        string poss = arr[dig[i]];
        cout<<poss<<" ";
        for(int j=0;j<poss.size();j++)
        {
            out.push_back(poss[j]);
            helper(i+1,dig,n,out,ans,arr);
            out.pop_back();
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
       vector<string> ans;
        int n = digits.size();
         if(n==0)
            return ans;
        int dig[n];
        for(int i=0;i<n;i++){
            dig[i]=digits[i]-'0';
        }
        
       
       
        string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        helper(0,dig,n,"",ans,arr);
        return ans;
    }
};