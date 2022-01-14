vector<string> generate(int N)
{
	vector<string> ans;
	
	for(int i=1;i<=N;i++){
	string s;
	int n=i;
	int j = 31;
	while(((n>>j)&1) == 0){
	    j--;
	}
	
	for(;j>=0;j--){
	    int bit = n>>j;
	    if(bit&1) s.push_back('1');
	    else s.push_back('0');
	    
	}
	ans.push_back(s);
	}
	return ans;
}
