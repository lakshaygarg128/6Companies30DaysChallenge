class Solution{
    public:
    //You need to complete this fucntion
    long long int  modulo = 1000000007;
    long long power(int N,int n)
    {
        
        if(n==1) return N;
        
        if(n&1){
            long long temp = power(N,n/2);
            return (((N*temp)%modulo)*temp)%modulo;
        }
        
            long long temp = power(N,n/2);
            return (((temp)%modulo)*temp)%modulo;
    }

};