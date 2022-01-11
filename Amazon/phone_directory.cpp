class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
       vector<vector<string>> ans;
       vector<string> str;
       
       for(int i =0;i<n;i++){
           str.push_back(contact[i]);
       }
       
       sort(str.begin(),str.end());
       
       int curr=0;
       
       for(auto x :s){
           
           for(int j=0;j<str.size();j++){
               if(str[j][curr]!=x){
                   str.erase(str.begin()+j);
                   j--;
               }
           }
           curr++;
       
           if(str.size()>0)
           ans.push_back(str);
           else
           ans.push_back({"0"});
       }
       
       return ans;
    }
};