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

