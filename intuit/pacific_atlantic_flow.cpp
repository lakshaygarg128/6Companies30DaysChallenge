class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int  n = heights.size(), m = heights[0].size();
        
        vector<vector<bool>> check1(n,vector<bool> (m,false));
        vector<vector<bool>> check2(n,vector<bool> (m,false));
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            dfs(heights,check1,i,0);
            dfs(heights,check2,i,m-1);
        }
        
            
        for(int j=0;j<m;j++){
            dfs(heights,check1,0,j);
            dfs(heights,check2,n-1,j);
            
        }
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check1[i][j] and check2[i][j]){
                    ans.push_back({i,j});
                    
                }
            }
        }
        
        return ans;
        
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        //up
        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);

    }
};