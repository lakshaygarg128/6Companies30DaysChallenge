class Solution {
    // MAPPING OF NODE ITS PARENT
    map<Node*,Node*> mp;
    // add of target node
    Node* add;
  public:
    int minTime(Node* root, int target) 
    {
        find_parent(root,target); 
        // array to check burnt tree or not
        int burnt[10001]={0};
        queue<Node*> q;
        q.push(add);
        burnt[target]=1;
        int time= 0;
        
        // Simple BFS 
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* temp =q.front();
                // checking for the child
                if(temp->right)
                if(!burnt[temp->right->data]){
                    burnt[temp->right->data]=1;
                    q.push(temp->right);
                }
                // checking for the child
                if(temp->left)
                if(!burnt[temp->left->data]){
                    burnt[temp->left->data]=1;
                    q.push(temp->left);
                }
                // checking for the parent
                if(mp[temp])
                if(!burnt[mp[temp]->data]){
                        burnt[mp[temp]->data]=1;
                        q.push(mp[temp]);
                }
                
                q.pop();
                
            }
          
         // if no new node is burnt during time of 1 sec  
        if(q.size()!=0)
        time++;
        
        }
        return time;
    }
    void find_parent(Node* root,int target){
        if(root==NULL) return;
        
        if(target==root->data) add=root;
        
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        
        find_parent(root->left,target);
        find_parent(root->right,target);
    }
};