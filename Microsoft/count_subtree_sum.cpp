int helper(Node *root,int X,int &x) {
    if(!root) return 0;
    else if(!root->left and !root->right and root->data == X) {
        x++;
        return X;
    } 
    
    int sum = root->data + helper(root->left,X,x) + helper(root->right,X,x);
    
    if(sum == X) x++;
    
    return sum;
    
}
int countSubtreesWithSumX(Node* root, int X)
{
	if(root==NULL) return 0;
	int count =0;
	helper(root,X,count);
	
	return count;
}