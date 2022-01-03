int damaged_toy(int n,int m,int k){
   int res = m%n + k -1 ;
   
   if(res==n) return res;
   
   return res%n;
} 