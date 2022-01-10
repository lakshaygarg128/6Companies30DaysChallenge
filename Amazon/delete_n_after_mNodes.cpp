class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        Node* temp = head;
        int n=N,m=M;
        
        while(temp!=NULL && temp->next!=NULL){
            if(m>1){
                temp=temp->next;
                m--;
                continue;
            }
            m=M;
            while(n-- && temp!=NULL && temp->next!=NULL){
                temp->next=temp->next->next;
            }
            if(temp!=NULL)temp=temp->next;
            n=N;
            
        }
 
        
    }
};