class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        bool neg=false;
        int n =str.size();
        int i =0;
        if(str[i]=='-'){
          neg= true;
          i++;
        } 
        int ans=0;
        
        while(i<n){
            if(str[i]>='0' and str[i]<='9'){
                int dig=str[i]-'0';
                ans=ans*10+dig;
            }else{
                return -1;
            }
            i++;
        }
        if(neg) ans*=-1;
        return ans;
        
        
    }
};