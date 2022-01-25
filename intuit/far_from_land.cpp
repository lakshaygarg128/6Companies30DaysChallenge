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
};int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];
 
    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
 
    // Initialize difference of two sums.
    int diff = INT_MAX;
 
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}