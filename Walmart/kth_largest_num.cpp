class Solution {
public:
    static bool compare(string a, string b){
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& arr, int k) {
        
        int n = arr.size();
    
        sort(arr.begin(),arr.end(),compare);
      
        return arr[n-k];
    }
};