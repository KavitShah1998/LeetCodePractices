#include <vector>
#include <stack>


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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> S;
        std::vector<int> traversal;
        
        TreeNode* this_node = nullptr;
        
        if(root)
            S.emplace(root);
        
        while(!S.empty()){
            
            /* Extract node data from stack top*/
            this_node = S.top();
            S.pop();
            
            /* Add data of the current node to vector of results*/
            traversal.push_back(this_node->val);
            
            if(this_node->right)
                S.emplace(this_node->right);
            
            if(this_node->left)
                S.emplace(this_node->left);
            
        }
        return traversal;
    }
    
};
