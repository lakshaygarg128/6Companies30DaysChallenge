
// PARTITION APPROACH WITH PATTERN OBSERVATION
class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        stack<int> st;
        int dig=1;
        string ans;
        for(int i =0;i<S.size();i++){
            if(S[i]=='D'){
                st.push(dig);
                dig++;
            }else{
                st.push(dig);
                dig++;
                
                while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(dig);
        while(!st.empty()){
                    ans+=to_string(st.top());
                    st.pop();
        }
        
        return ans;
    }
};