class Solution{
public:
    string decodedString(string s){
          stack<char> stack;
        string ans;
        int n = s.size();
        for(int i=0;i<n;i++){
            
            if(s[i]!=']'){
                stack.push(s[i]);
            }else{
                string str ="";
                
                while(stack.top()!='['){
                    str= stack.top()+ str;
                    stack.pop();
                }
                
                stack.pop();
                
                string times="";
                while(!stack.empty() and stack.top()<='9' and stack.top()>='0'){
                    times = stack.top()+times;
                    stack.pop();
                }
                
                int times_num = stoi(times);
                
                while(times_num--){
                    for(int j = 0;j<str.size();j++){
                        stack.push(str[j]);
                    }
                }
                
            }
        
        }
        
        
        while(!stack.empty()){
            ans= stack.top()+ans;
            stack.pop();
        }
        
        return ans;
    }
};