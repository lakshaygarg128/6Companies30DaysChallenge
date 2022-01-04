// FIND NO. OF SQUARES 
 /*
    1X1 => N*N
    2X2 => N-1*N-1
    ....
    NXN => 1*1

 */
class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long ans=0;
        for(long long i = 1;i<=N;i++){
            ans+=i*i;
        }
        return ans;
    }
};


// 1^2 + 2^2 + 3^2 . . . .n^2 = n*(n+1)*(2*n+1)/6

 class Solution {
  public:
    long long squaresInChessBoard(long long n) {
       return n*(n+1)*(2*n+1)/6;
    }
};



