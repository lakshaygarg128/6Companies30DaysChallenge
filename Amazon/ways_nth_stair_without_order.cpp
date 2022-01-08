long long countWays(int m)
   {

      //we just need to count how many no. of 2's we can possibly have for the given value of m.

// for e.g if m=5 

//case1 : (zero 2 : 1 1 1 1 1 )

//case2 : (one 2 : 2 1 1 1)

//case3 : (two 2: 2 2 1)

// and since the order doesn't matter , we can simply return how many times we can use 2
       return (m/2)+1;
   }