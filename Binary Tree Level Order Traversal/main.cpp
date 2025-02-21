#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                // Add the node's value to the current level
                level.push_back(currentNode->val);
                
                // Push the left and right children to the queue
                if (currentNode->left != NULL) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != NULL) {
                    q.push(currentNode->right);
                }
            }
            
            // Add the current level to the result
            result.push_back(level);
        }
        
        return result;
    }
};

// Helper function to create a tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Main function to test the code
int main() {
    Solution sol;
    TreeNode* root = createTree();
    
    vector<vector<int>> result = sol.levelOrder(root);
    
    // Output the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
