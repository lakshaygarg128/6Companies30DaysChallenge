class Solution{
    public:
    string amendSentence (string s)
    {
        int i = 1,n = s.size();
        string ans;
        ans.push_back(tolower(s[0]));
        while(i<n and s[i]>='a' and s[i]<='z'){
            ans.push_back(s[i]);
            i++;
        }
        while(i<n){
            ans.push_back(' ');
            ans.push_back(tolower(s[i]));
            i++;
            while(i<n and s[i]>='a' and s[i]<='z'){
                ans.push_back(s[i]);
                i++;
            }   
            
        }
        return ans;
    }
};