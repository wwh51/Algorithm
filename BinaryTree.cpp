bool isBalanced (TreeNode* root) {
    return balancedHeight(root) >= 0;
}

bool balancedHeight (TreeNode* root) {
        if(!root) return 0;
        int left = balancedHeight(root->left);
        int right = balancedHeight(root->right);
        if(left < 0 || right < 0 || abs(left-right) > 1 )
            return -1;
        return max(left+right) + 1;
}

class BT2BST_class
{
public:

  void BT2BST(Node *root) {
        int swap;
        do {
                swap = 0;
                dfs(NULL, root, swap);
        } while(swap);
}

Node* dfs(Node *pred, Node *curNode, int& swap) {
        if(curNode == NULL)
                return NULL;
        Node *p = dfs(pred, curNode->left, swap);
        if(!p) 
            p = pred;
        if(p && p->value > curNode->value) {
                swap(curNode->value, p->value);
                swap++;
        }
        p = dfs(curNode, curNode->right, swap);
        return (p ? p : curNode);
}


};


// Lowest Common Ancestor
// the following way has a bug, if only one in p and q is not child of root, it still return.


Node *LCA(Node *root,Node *p,Node *q){
  if(!root) 
    return NULL;
  if(root == p || root == q)
    return root;
  Node *L = LCA(root->left,p,q);
  Node *R = LCA(root->right,p,q);
  if(L && R)
    return root;  // if p and q are on both sides
  return   L ? L:R;  // either one of p,q is on one side OR p,q is not in L&R subtrees
}

// 

Node *LCA_Correct(Node *root,Node *p,Node *q){
  if(!root || !p || !q)
    return NULL;
  Node * lca = LCA(root, p, q);
  if(lca == p)
    return IsFather(p,q) ? p : NULL;
  else if(lca == q)
    return IsFather(q,p) ? q : NULL;

  return lca;
}


// for  BST
Node *LCA(Node *root,Node *p,Node *q){
  if(!root || !p || !q)
    return NULL;
  if(max(p->data,q->data) < root->data)
    return LCA(root->left, p, q);
  else if (min(p->data,q->data) > root->data)
    return LCA(root->right,p,q);
  else
    return root;
}
