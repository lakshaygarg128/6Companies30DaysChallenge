class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] && dfs(i,j,n,m,board,word,vis,0)){
                    return true;
                }
            }
        } 
        return false;
    }
    
    bool dfs(int i ,int j, int n ,int m, vector<vector<char>>& arr, string w, vector<vector<int>> &vis, int k){
        if(i>=n || i<0 || j<0 || j>=m) return false;
        if(vis[i][j]==1) return false;
        
        if(w[k]!=arr[i][j]) return false;
        if(k==w.size()-1){
           // cout<<arr[i][j];
            return true;
        }
        vis[i][j]=1;
        bool ans = dfs(i+1,j,n,m,arr,w,vis,k+1) || dfs(i-1,j,n,m,arr,w,vis,k+1)
            || dfs(i,j+1,n,m,arr,w,vis,k+1) || dfs(i,j-1,n,m,arr,w,vis,k+1);
            vis[i][j]=0;
            return ans;
    }

};