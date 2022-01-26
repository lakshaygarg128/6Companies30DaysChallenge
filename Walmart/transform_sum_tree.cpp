class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        helper(node);
    }
    int helper(Node* node){
        if(node==NULL) return 0;
        
        int l = helper(node->left);
        int r = helper(node->right);
        
        int cur =l+r+ node->data;
        
        node->data = l+r;
        
        return cur;
        
    }
};