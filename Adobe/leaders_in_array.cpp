class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
       
       vector<int> ans;
       stack<int> s;
       s.push(a[n-1]);
      
       for(int i=n-2;i>=0;i--){
           if(s.top()<=a[i]){
               s.push(a[i]);
              
           }
       }
       while(!s.empty()){
           ans.push_back(s.top());
           s.pop();
       }
       
       
        return ans;
    }
};