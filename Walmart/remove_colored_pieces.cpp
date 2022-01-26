class Solution {
public:
    bool winnerOfGame(string colors) {
       
        
        int  n = colors.size();
        
        int i=0, alice=0,bob=0;
        while(i<n){
            int j=i;
            while(j+1<n and colors[j]==colors[j+1]){
                j++;
            }
            if(colors[j]=='A'){
                alice+=(j-i-1>=0 ? j-i-1 : 0 );
            }else{
                 bob+=(j-i-1>=0 ? j-i-1 : 0 );
            }
            i=j+1;
        }
        
        if(alice>bob)return true;
        return false;
    }
};