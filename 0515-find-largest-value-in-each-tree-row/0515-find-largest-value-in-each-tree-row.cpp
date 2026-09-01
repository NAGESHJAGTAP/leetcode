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
    vector<int> largestValues(TreeNode* root) {
         vector<int> result;
         if(root == NULL){
            return result;
         };

         queue<TreeNode*>q;
         q.push(root);

         while(!q.empty()){
           int largest=INT_MIN;
           int size=q.size();
           
           for(int i=0; i<size; i++){
            TreeNode*total=q.front();
            q.pop();
            largest = max(largest, total->val);

            if(total->left) q.push(total->left);
            if(total->right) q.push(total->right);
           }

           result.push_back(largest);
         }
         return result;
    }
};