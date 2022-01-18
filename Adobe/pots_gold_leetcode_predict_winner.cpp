class Solution {
public:
    int helper(vector<int> &nums,int i,int j){
        if(i>j) return 0;
        
        int choice1 = nums[i]+min(helper(nums,i+2,j),helper(nums,i+1,j-1));
        int choice2 = nums[j]+min(helper(nums,i+1,j-1),helper(nums,i,j-2));
        return max(choice1,choice2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        int i =0,j=n-1,sum=0;
        int best = helper(nums,i,j);
        
        cout<<best;
        for(auto x:nums) sum+=x;
        
        if(best>=sum-best) return true;
        
        return false;
        
    }
};