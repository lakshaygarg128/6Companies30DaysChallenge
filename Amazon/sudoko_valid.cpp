class Solution{
public:
    int isValid(vector<vector<int>> mat){
        map<string,int> mp;
        int row[10][10] ={0},col[10][10] ={0},box[10][10] ={0};
        for(int i=0;i<9;i++){
            for(int j =0;j<9;j++){
                if(mat[i][j]!=0){
               
                if(row[mat[i][j]][i+1]==1 || col[mat[i][j]][j+1]==1 || box[mat[i][j]][((i)/3)*3+((j)/3)]==1){
                return 0;
                }
                row[mat[i][j]][i+1]=1;
                col[mat[i][j]][j+1]=1;
                box[mat[i][j]][((i)/3)*3+((j)/3)]=1;
                }
            }
        }
        
        return 1;
    }
};