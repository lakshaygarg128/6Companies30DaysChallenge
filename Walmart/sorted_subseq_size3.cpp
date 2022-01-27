class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        if(N<3) return {};
        vector<int> left(N),right(N);
        int temp = INT_MAX;
        for(int i=0; i<N; i++) {
            left[i]=temp;
            temp=min(temp,arr[i]);
        }
        temp = INT_MIN;
        for(int i=N-1; i>=0; i--) {
            right[i]=temp;
            temp=max(temp,arr[i]);
        }
        
        for(int i=0;i<N;i++){
            if(left[i]<arr[i] and arr[i]<right[i]){
                return {left[i],arr[i],right[i]};
            }
        }
        
        return {};
    }
};