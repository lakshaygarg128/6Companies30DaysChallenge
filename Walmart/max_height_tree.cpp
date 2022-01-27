class Solution{
public:
    int height(int X){
        // roots of n^2 + n + 2*X
        // value of n==> n(n+1)/2 >X
         return (-1 + sqrt(1 + 8*X)) / 2;
    }
};