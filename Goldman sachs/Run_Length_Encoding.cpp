string encode(string src)
{    
    string ans;
    int i=0,n=src.size();
    
  for(i=0;i<n;i++){
      char cur = src[i];
      int count=1;
      while(i<n-1 && src[i]==src[i+1]){
          count++;
          i++;
      }
      stack<char> stack;
      while(count){
          int last = count%10;
          count/=10;
          stack.push(48+last);
      }
      ans+=cur;
      while(!stack.empty()){
          ans+=stack.top();
          stack.pop();
      }
  }
  return ans;
}