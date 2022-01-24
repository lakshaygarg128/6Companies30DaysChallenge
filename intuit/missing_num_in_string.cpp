long long sto(string s)
{
    long long x=0;
    for(int i=0;i<s.size();i++)
      x=x*10+s[i]-'0';
    return x;
}

int missingNumber(const string& str)
{
    long long n = str.size();
    for(int l=1 ; l<=6;l++){
        string temp = "";
        int  length = l;
        long long  i=0;
        //cout<<l;
        while(i<n and length--){
            temp+=str[i++];
        }
        long long j = i,prev=sto(temp),ans,count=0,flag=1;
        temp="";
        while(j<n){
            temp+=str[j++];
            long long num = sto(temp);
            
            if(prev+1==num){
                temp="";
                prev=num;
            }else
                if(prev+2==num){
                    count++;
                    temp="";
                    ans=prev+1;
                    prev=num;
                }else
                    if(prev<=num){
                        flag=0;
                        break;
                    }
           
        }
         if(flag==1 and count==1) return ans;
    }
    return -1;
}