class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        int  i=0;
        for(auto x : string_list){
            string y=x;
            sort(y.begin(),y.end());
            mp[y].push_back(x);
            i++;
        
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};