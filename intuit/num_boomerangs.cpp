class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            // checking each point with the same distance to diffrent points
            map<double,int> mp;
            
            for(int j=0;j<n;j++){    
                if(i!=j){
                  double dis=pow((p[i][0]-p[j][0]),2)+pow((p[i][1]-p[j][1]),2);
                  mp[dis]++;
                }
            }
            
            for(auto x:mp){
                // more than  point having same distance
                if( x.second>=2){
                    // calculating the all permutations of (j,k) of a Boomerangs
                    ans+=(x.second)*(x.second-1);
                }
            }
        }
            return ans;
        
    }
};