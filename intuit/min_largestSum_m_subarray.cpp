class Solution {
public:
    bool canbe(int max_sum,vector<int> &nums,int m ) {
        int num_subarr = 1,sum=0;
        int n =nums.size();
        for(int i=0; i<n; i++) {
            sum+=nums[i];
            if(sum>max_sum){
                num_subarr++;
                sum=nums[i];
                if(num_subarr>m) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        
        long long sum =0;
        int minval=0;
        
        for(auto x: nums){
            minval = max(minval,x);
            sum+=x;
        }
        
        while(minval<sum){
            int mid = minval + (sum-minval)/2;
            if(canbe(mid,nums,m)){
                sum = mid;
            }else{
                minval=mid+1;
            }
        }
        return minval;
 
    }
};