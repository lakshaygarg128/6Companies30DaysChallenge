class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p=1;
        int i=0,j=0;
        int count = 0;
        // sliding window
        while(i<n and j<n){
            p=p*a[j];
            while(i<n and p>=k){
                p=p/a[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
        
    }
};