class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // TAKING TWO POINTER AND USING TWO SUM APPROACH
        int i=0,j=i+1,n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++){
                int sum=k-arr[i]-arr[j];
                
                int left = j+1,right=n-1;
                // Two sum Problem
                while(left<right){
                    if(sum==arr[left]+arr[right]){
                        ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                        int prevl = arr[left],prevr=arr[right];
                        while(left<right and arr[left]==prevl) left++;
                        while(left<right and arr[right]==prevr) right--;
                        continue;
                    }
                    if(sum>arr[left]+arr[right]){
                        left++;
                    }else{
                        right--;
                    }
                }
                
                while(j+1<n and arr[j]==arr[j+1]) j++;
            }
            while(i+1<n and arr[i]==arr[i+1]) i++;
        }
        
        return ans;
    }
};