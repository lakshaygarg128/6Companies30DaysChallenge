


// RECURSIVE SOLUTION 3MS IN LEETCODE
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(n1<n2){
            return gcdOfStrings(str2,str1);
        }
        int start =0;
        while(start+n2-1<n1){
            if(str2!=str1.substr(start,n2)){
                return ""; 
            }
            start+=n2;
        }
        //if(n1==n2) return str1; 

        if((n1-n2)%n2==0){
            return str1.substr(0,n2);
        }
            return gcdOfStrings(str2,str1.substr(n1-((n1-n2)%n2),(n1-n2)%n2));
        
        
    }
};

