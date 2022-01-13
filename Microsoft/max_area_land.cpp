class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
             
             if(grid[i][j] and vis[i][j]==0)   
             ans=max(ans,helper(grid,i,j,vis,n,m));
            }
        }
        
        return ans;
        
    }
    
    int helper(vector<vector<int>> &grid,int i,int y,vector<vector<int>> &vis,int n, int m){
        if(i>=0 and i<n and y>=0 and y<m and vis[i][y]==0 and grid[i][y]){
            vis[i][y]=1;
            int ans = 1+helper(grid,i-1,y,vis,n,m)+
            helper(grid,i+1,y,vis,n,m)+
            helper(grid,i,y-1,vis,n,m)+
            helper(grid,i,y+1,vis,n,m)+
            helper(grid,i-1,y-1,vis,n,m)+
            helper(grid,i+1,y+1,vis,n,m)+
            helper(grid,i-1,y+1,vis,n,m)+
            helper(grid,i+1,y-1,vis,n,m);
            
            return ans;
        }
        return 0;
    }
};