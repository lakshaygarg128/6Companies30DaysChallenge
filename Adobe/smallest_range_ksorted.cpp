class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        //int n = a[0].size(),k=a.size();
        vector<pair<int,int>> vec;
         for (int i = 0; i < k; ++i)
            for (int j = 0 ;j<n;j++){
                vec.push_back({a[i][j], i});
                //cout<<a[i][j];
            }
         
         sort(vec.begin(),vec.end());
         pair<int,int> ans = {vec.front().first,vec.back().first};
         map<int,int>mp;
         int curr=0;
         int total = k;
         int j=0;
         int mini = vec.back().first - vec[0].first + 1; 
        
         for(int i=0; i< vec.size() ;i++){
             mp[vec[i].second]++;
             if(mp[vec[i].second]==1) curr++;
             
             if(curr==total){
                 
                 while(curr==total){
                     if(mp[vec[j].second]==1){
                         break;
                     }else{
                         mp[vec[j].second]--;
                         j++;
                     }
                 }
                 if(mini>(vec[i].first-vec[j].first+1)){
                     mini=vec[i].first-vec[j].first+1;
                     ans={vec[j].first,vec[i].first};
                 }
             }
         }
         return ans;
    }
    
};
