/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ret = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size(), start = q.front().second, end = q.back().second;
            ret = max(ret, end - start + 1);
            while (size--) {
                auto curr = q.front();
                curr.second -= start;
                if (curr.first->left) {
                    q.push({curr.first->left, 2*curr.second});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, 2*curr.second + 1});
                }
                q.pop();
            }
        }
        return ret;
    }
};
