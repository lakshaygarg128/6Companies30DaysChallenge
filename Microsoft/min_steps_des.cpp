class Solution{
public:
    int minSteps(int D){
        
     int steps=0,pos=0;
     D=abs(D);
     
     while(pos<D){
         steps++;
         pos+=steps;
     }
     if(pos==D) return steps;
     
     while((pos-D)%2!=0){
         steps++;
         pos+=steps;
     }
     
     return steps;
       
    }
   
};