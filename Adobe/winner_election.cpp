class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
       
        map<string,int> mp;
        
        for(int i = 0; i < n ; i++ ){
            mp[arr[i]]++;
        }
        int max=0;
        string ans = "";
        
        for(auto x:mp){
            if(max<=x.second){
                
                if(ans>x.first and max==x.second){
                    ans=x.first;
                }else{
                    if(max!=x.second){
                        ans=x.first;
                    }
                }
                max=x.second;
            }
        }
        
        vector<string> v;
        v.push_back(ans);
        v.push_back(to_string(max));
        return v;
    }
};