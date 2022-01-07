class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       deque<int> dq;
        
        vector<int> ans;
        
        int i =0,j=0;
        
        
        while(j<k){
           
                while(!dq.empty() && dq.back()<arr[j]){
                    dq.pop_back();
                }
            
                dq.push_back(arr[j]);
            
            j++;
        }
       // cout<<j<<" ";
        ans.push_back(dq.front());
        while(j<n){
            if(arr[i]==dq.front()){
                dq.pop_front();
            }
            if(arr[j]>dq.back()){
                while(!dq.empty() && dq.back()<arr[j]){
                    dq.pop_back();
                }
                dq.push_back(arr[j]);
            }else{
               
                    dq.push_back(arr[j]);
                
            }
            i++;
            j++;
            ans.push_back(dq.front());
        }
        return ans;
    }
};