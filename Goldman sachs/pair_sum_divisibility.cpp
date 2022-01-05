class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
       
       int rem[k+1] = {0};
       int n = nums.size();
       // checking for odd no. of elements
         if (n & 1)
        return false;
       
       // Occurance of remainder
       for(int i =0;i<n;i++){
           rem[nums[i]%k]++;
       }
       // check that pairs can be made
       for(int i=0;i<k;i++)
       {
           if(k-i!=i and i!=0){
               if(rem[k-i]!=rem[i]){
                   return false;
               }
           }else{
               if(rem[i]%2!=0){
                   return false;
               }
           }
           
       }
       return true;
    }
};