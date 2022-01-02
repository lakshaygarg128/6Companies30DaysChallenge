class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
	    ull i=0,j=0,k=0;
	    vector<ull> arr(1,1);
	    
	    while(arr.size()<n){
	        arr.push_back(min(arr[i]*2,min(arr[j]*3,arr[k]*5)));
	        if(arr.back()==arr[i]*2) i++;
	        if(arr.back()==arr[j]*3) j++;
	        if(arr.back()==arr[k]*5) k++;
	    }
	    return arr.back();
	    
	}
};