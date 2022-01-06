
// My code
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i = 0,j=0;
        int n = arr.size();
        int max_length=0;
        if(n<3) return 0;
       
        while(i<n and j<n and i<=j){
            
             for(int k=i;k<n-1;k++){
                    if(arr[k]<arr[k+1]){
                        i=k;
                        j=k;
                        break;
                    }
                }
            
        if(i+1<n and arr[i]>=arr[i+1]) break;
            
            if(i==n-1) break; 
            
            while(j+1<n and arr[j]<arr[j+1]){
                j++;
            }
            
          if(j==n-1) break; 
            
            if(arr[j]==arr[j+1]){
                i=j=j+1;
                continue;
            }
            
            
            while(j+1<n and arr[j]>arr[j+1]){
                j++;
            }
            
            cout<<arr[j]<<" "<<arr[i]<<" "<<j-i+1<<endl;
            
            if(max_length < (j-i+1)){
                max_length=j-i+1;
            }
            
            i=j;
            
        }  
        return max_length;
    }
};





// Simple Code
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int maxLength = 0;
        int i = 1;
        
        while (i < A.size()) {
            int increasing = 0, decreasing = 0;
            
            while(i < A.size() && A[i - 1] < A[i]) i++, increasing++;
            while(i < A.size() && A[i - 1] > A[i]) i++, decreasing++;
            
            if (increasing > 0 && decreasing > 0) maxLength = max(maxLength, increasing + decreasing + 1);
            
            while(i < A.size() && A[i - 1] == A[i]) i++;
        }
        return maxLength;
    }
};