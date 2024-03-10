#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
        int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* ptr, vector<int>& result) {
        if (!ptr) return;
        dfs(ptr->left, result);
        result.push_back(ptr->val);
        dfs(ptr->right, result);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        dfs(root, result);

        return result;
    }
};