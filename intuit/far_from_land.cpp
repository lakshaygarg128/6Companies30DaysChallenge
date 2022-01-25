class Solution {
public:
    int maxDistance(vector<vector<int>>& grid, int steps = 0) {
        queue<pair<int,int>> q;

        int n = grid.size(), m = grid[0].size();
        for(int i = 0 ;i < n; i++ ) {
            for(int  j = 0 ; j < m ; j++) {
                if(grid[i][j]==1){

                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }

        while(!q.empty()){
            ++steps;
            int n1 = q.size();
            while(n1--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==0){
                    grid[i][j]=steps;
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }

        return steps == 1 ? -1 : steps-1;
    }
};