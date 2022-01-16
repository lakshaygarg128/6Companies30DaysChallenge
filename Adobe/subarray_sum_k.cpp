class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
      long long int sum = arr[0];
      int i =0;
      while(i<n and sum<s){
          i++;
          sum+=arr[i];
      }
    
      int j=0; 
      while(i<n and (j<n) and (j<=i)){
         
          if(sum==s){
              return {j+1,i+1};
          }
          if(sum>s){
             
              
              if(i==j and sum>s){
                //   cout<<sum;
                sum=arr[i+1];
                i++;
                j++;
                continue;
              } 
              sum-=arr[j];
              j++;
              
              
          }else{
              
              sum+=arr[i+1];
              i++;
          }
      }
     //cout<<sum;
     if(sum!=s)
      return {-1};
      
      return {i+1,j+1};
      
    }
};