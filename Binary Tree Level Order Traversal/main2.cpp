#include <iostream>
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
    // Recursive function to collect nodes at each level
    void levelOrderRecursiveHelper(TreeNode* root, int level, vector<vector<int>>& result) {
        if (root == NULL) return;
        
        // Ensure the result vector is large enough to hold the current level
        if (result.size() <= level) {
            result.push_back({});
        }
        
        // Add current node value to the appropriate level
        result[level].push_back(root->val);
        
        // Recursively process the left and right subtrees
        levelOrderRecursiveHelper(root->left, level + 1, result);
        levelOrderRecursiveHelper(root->right, level + 1, result);
    }

    // Main function to return level order traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderRecursiveHelper(root, 0, result);
        return result;
    }

    // Function to print tree (for better visualization)
    void printTree(TreeNode* root, int space = 0, int COUNT = 10) {
        if (root == NULL) return;

        // Increase distance between levels
        space += COUNT;

        // Print right child first (top to bottom)
        printTree(root->right, space);

        // Print current node after space count
        cout << endl;
        for (int i = COUNT; i < space; i++) cout << " ";
        cout << root->val << "\n";

        // Print left child
        printTree(root->left, space);
    }
};

// Helper function to create a sample tree
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

// Main function to test
int main() {
    Solution sol;
    TreeNode* root = createTree();

    // Print tree structure beautifully
    cout << "Tree structure:" << endl;
    sol.printTree(root);

    // Get the level order traversal
    vector<vector<int>> result = sol.levelOrder(root);

    // Print level order traversal
    cout << "\nLevel Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
