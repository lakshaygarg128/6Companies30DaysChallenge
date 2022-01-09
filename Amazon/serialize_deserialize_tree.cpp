class Solution
{
    vector<int> list;
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        // storing the nodes with NULL child in pre order 
        helper(root);
      
        return list;
    }
    
    void helper(Node * root){
        if(root==NULL){
            list.push_back((int)NULL);
            return ;
        }
        
        list.push_back(root->data);
        helper(root->left);
        helper(root->right);
    }
    
    //Function to deserialize a list and construct the tree.
    int indx=0;
    Node * deSerialize(vector<int> &A)
    {
       if(indx>=A.size() || A[indx]==NULL){ 
           indx++;
           return NULL; }
       
      Node * root = new Node(A[indx++]);
      
      root->left = deSerialize(A);
      root->right = deSerialize(A);
      
      return root;
    }

};