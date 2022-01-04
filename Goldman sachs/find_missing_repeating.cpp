// Solved using no extra space and in O(N) time
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int ans1,ans2;
        for(int i =0;i<n;i++){
            if(arr[abs(arr[i])-1]<0){
                ans1=abs(arr[i]);
            }else{
                arr[abs(arr[i])-1]*=-1;
            }
        }
        for(int i =0;i<n;i++){
            if(arr[i]>0){
                ans2=i+1;
            }
        }
       int *ans = new int[2];
       ans[0]=ans1;
       ans[1]=ans2;
       return ans;
        
    }
};