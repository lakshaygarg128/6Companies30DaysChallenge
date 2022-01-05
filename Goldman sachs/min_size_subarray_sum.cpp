// SLIDING WINDOW

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0 , j = 0, sum=0,n = nums.size();
        while(j<n and i<=j){
            sum+=nums[j];
            if(sum>=target){
                break;
            }
            j++;
        }
        // if sum is not possible
        if(sum<target) return 0;
         
        // First subarray with sum>=target
        int min_size = j-i+1;
       
        
        while(j<n and i<=j){
            // shrink the size
            sum=sum-nums[i];
            i++;
            
            // sum not obtained so sliding the window
            if(sum<target){
                j++;
                if(j<n)
                sum+=nums[j];
                continue;
            }
            // sum obtained and checking size of window
            if(min_size>j-i+1){
                min_size=j-i+1;
            }       
        }
        return min_size;
    }
};