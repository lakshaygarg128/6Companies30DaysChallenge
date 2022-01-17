class Solution
{
    vector<string> ans;
    public:
    vector<string> AllParenthesis(int n) 
    {
        helper(n,"",n,n);
        return ans;
    }
    void helper(int n,string s,int counto,int countc){
        if(counto==0 and countc==0){
            ans.push_back(s);
            return;
        }
        if(counto<0 || countc<0) return ;
        if(counto==countc){
            helper(n,s+"(",counto-1,countc);
        }
        
        if(counto!=countc){
            helper(n,s+")",counto,countc-1);
            helper(n,s+"(",counto-1,countc);
        }
    }
};