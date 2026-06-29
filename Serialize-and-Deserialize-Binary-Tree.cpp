1#include <string>
2#include <sstream>
3
4using namespace std;
5
6class Codec {
7private:
8    // Helper function for serialization (Preorder Traversal)
9    void serializeHelper(TreeNode* root, stringstream& ss) {
10        if (!root) {
11            ss << "#,";
12            return;
13        }
14        ss << root->val << ",";
15        serializeHelper(root->left, ss);
16        serializeHelper(root->right, ss);
17    }
18
19    // Helper function for deserialization
20    TreeNode* deserializeHelper(stringstream& ss) {
21        string valStr;
22        if (!getline(ss, valStr, ',')) {
23            return nullptr;
24        }
25        
26        if (valStr == "#") {
27            return nullptr;
28        }
29        
30        TreeNode* root = new TreeNode(stoi(valStr));
31        root->left = deserializeHelper(ss);
32        root->right = deserializeHelper(ss);
33        return root;
34    }
35
36public:
37    // Encodes a tree to a single string.
38    string serialize(TreeNode* root) {
39        stringstream ss;
40        serializeHelper(root, ss);
41        return ss.str();
42    }
43
44    // Decodes your encoded data to tree.
45    TreeNode* deserialize(string data) {
46        stringstream ss(data);
47        return deserializeHelper(ss);
48    }
49};