1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(NULL), right(NULL) {}
8 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right)
10 *         : val(x), left(left), right(right) {}
11 * };
12 */
13
14class Solution {
15public:
16
17    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
18
19        
20        map<int, int> inMap;
21
22        for (int i = 0; i < inorder.size(); i++) {
23            inMap[inorder[i]] = i;
24        }
25
26        return buildTree(preorder,
27                         0,
28                         preorder.size() - 1,
29                         inorder,
30                         0,
31                         inorder.size() - 1,
32                         inMap);
33    }
34
35private:
36
37    TreeNode* buildTree(vector<int>& preorder,
38                        int preStart,
39                        int preEnd,
40                        vector<int>& inorder,
41                        int inStart,
42                        int inEnd,
43                        map<int, int>& inMap) {
44
45        
46        if (preStart > preEnd || inStart > inEnd) {
47            return NULL;
48        }
49
50
51        TreeNode* root = new TreeNode(preorder[preStart]);
52
53        
54        int inRoot = inMap[root->val];
55
56        
57        int numsLeft = inRoot - inStart;
58
59
60        root->left = buildTree(preorder,
61                               preStart + 1,
62                               preStart + numsLeft,
63                               inorder,
64                               inStart,
65                               inRoot - 1,
66                               inMap);
67
68
69        root->right = buildTree(preorder,
70                                preStart + numsLeft + 1,
71                                preEnd,
72                                inorder,
73                                inRoot + 1,
74                                inEnd,
75                                inMap);
76
77        return root;
78    }
79};