class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int direct=0;
        int fr=0,lr=r-1,fc=0,lc=c-1;
      //  cout<<matrix[0][1];
        
        while(fr<=lr and fc<=lc){
            if(direct==0){
                for(int i=fc;i<=lc;i++){
                    ans.push_back(matrix[fr][i]);
                    
                }
                fr++;
                direct++;
            }else{
                if(direct==1){
                    
                for(int i=fr;i<=lr;i++)
                    ans.push_back(matrix[i][lc]);
                    lc--;
                
                direct++;
                }else{
                    if(direct==2){
                        
                for(int i=lc;i>=fc;i--)
                    ans.push_back(matrix[lr][i]);
                    lr--;
                
                direct++;
                    }else{
                        
                for(int i=lr;i>=fr;i--)
                    ans.push_back(matrix[i][fc]);
                    fc++;
                
                direct=0;
                    }
                }
                
            }
        }
        return ans;
    }
};