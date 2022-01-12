class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> s;
       s.push({0,price[0]});
       
       int i = 1;
       vector<int> ans;
       ans.push_back(1);
       while(i<n){
           while(!s.empty() && s.top().second<=price[i]){
               s.pop();
           }
           if(!s.empty())
           ans.push_back(i-s.top().first);
           else
           ans.push_back(i+1);
           
           s.push({i,price[i]});
           i++;
       }
       
       return ans;
    }
};
