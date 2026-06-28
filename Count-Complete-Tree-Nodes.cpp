1class Solution {
2public:
3    int countNodes(TreeNode* root) {
4
5        if(root == NULL)
6            return 0;
7
8        return 1 + countNodes(root->left) + countNodes(root->right);
9    }
10};