class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int prevcount =0;
        
        vector<int> vis(V,0);
        
                dfs(c,adj,vis,c,d);
           
        return !vis[d];
        
    
    }
    
   
    void dfs(int i , vector<int> adj[], vector<int> &vis,int c,int d){
        
        if(vis[i]) return;
        
        vis[i]=1;
        for(auto x : adj[i]){
            if((i==c and x==d) || (i==d and x==c)) continue;
            dfs(x,adj,vis,c,d);
        }
        return;
    }
};