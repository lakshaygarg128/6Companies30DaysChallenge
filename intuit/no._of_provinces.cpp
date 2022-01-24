class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i =0; i < n ; i++ ) 
                if(vis[i]==0){
                   count++;
                    dfs(i,mat,vis);
                }
        
        return count;
        
        
    }
    void dfs(int cur, vector<vector<int>> &mat,vector<int> &vis){
        vis[cur]=1;
        for(int i =0 ;i < mat.size() ; i++){
            if(vis[i]==0 and mat[cur][i]){
                dfs(i,mat,vis);
            }
        }
    }
    
};