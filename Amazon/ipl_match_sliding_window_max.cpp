class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        
        vector<int> ans;
        
        int i =0,j=0;
       // dq.push_back(arr[i]);
        
       for(i=0;i<k;i++)
        {
            while(!dq.empty() && dq.back()<arr[i]) dq.pop_back();
            dq.push_back(arr[i]);
        }

        j=k-1;
            i=0;
        
        while(j<n-1){
            ans.push_back(dq.front());
            if(arr[i]==dq.front()){
                dq.pop_front();
            }
            i++;j++;
            if(arr[j]>dq.back()){
                while(!dq.empty() && dq.back()<arr[j]){
                    dq.pop_back();
                }
            }
                dq.push_back(arr[j]);
            
        }
        ans.push_back(dq.front());
        return ans;
        
    }
};