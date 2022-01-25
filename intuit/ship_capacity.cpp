class Solution {
public:
    bool canbe(int mid,vector<int>& weights,int m){
        int sub_arr=1,sum=0,n=weights.size();
        for(int i=0; i<n; i++) {
            sum+=weights[i];
            if(sum>mid){
                sub_arr++;
                sum=weights[i];
                if(sub_arr>m) return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum= 0, minval=0;
        
        for(auto x: weights){
            sum+=x;
            minval = max(minval,x);
        }
        
        
        while(minval<sum){
            int mid = minval + (sum-minval)/2;
           // cout<<mid<<" ";
            if(canbe(mid,weights,days)){
                sum=mid;
            }else{
                minval = mid+1;
            }
        }
        
        return minval;
    }
};