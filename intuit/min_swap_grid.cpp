class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<int> vec;
        for(int i = 0;i<n;i++){
            int count=0;
            for(int j=n-1;j>0;j--){
                if(grid[i][j]==0){
                    count++;
                }else{
                    break;
                }
            }
            vec.push_back(count);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
           if(vec[i]<n-1-i)
            {
                int j=i;
                while(j<n and  vec[j]<n-1-i) j++;
                if(j==n) return -1;
                while(i<j)
                {
                    swap(vec[j],vec[j-1]);
                    ans++;
                    j--;
                }
            }
        }
        
        return ans;
        
    }
};