class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
            long long sum = 0;
           
            long long ans = -1;
        
        vector<pair<int,int>> arr;
        
        for(auto x=0;x<n;x++){
            arr.push_back({efficiency[x],speed[x]});
        }
        
        priority_queue<int, vector<int>, greater<int> > mh;
        
        sort(arr.begin(),arr.end());
        
        for(int  i = n-1; i >= 0; i--) {
            sum+= arr[i].second;
            mh.push(arr[i].second);
            
            if(mh.size() > k){
                sum-= mh.top();
                mh.pop();
            }
            
            ans = max(ans,(arr[i].first*sum));
            
        }
        return ans%1000000007;
        
    }
};