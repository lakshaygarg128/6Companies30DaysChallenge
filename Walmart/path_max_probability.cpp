class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int x=0;x<edges.size();x++){
            adj[edges[x][0]].push_back({edges[x][1],-1*log(succProb[x])});
            adj[edges[x][1]].push_back({edges[x][0],-1*log(succProb[x])});
        }
        vector<double> dis(n,INT_MAX);
        
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        
        pq.push({0.0,start});
        dis[start]=0.00000;
        
        while(!pq.empty()){
            //double cur_dis = pq.top().first;
            int curr = pq.top().second;
            
            pq.pop();
            
            for(auto x : adj[curr]){
                if(dis[curr]+x.second < dis[x.first]){
                    dis[x.first]=dis[curr]+x.second;
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        
        for(auto x: dis)cout<<exp(-1*x)<<" ";
        if(dis[end]==INT_MAX) return (double)0.000;
        return exp(-1*dis[end]);
        
        
        
    }
};