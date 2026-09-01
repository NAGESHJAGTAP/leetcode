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
    int maxLevelSum(TreeNode* root) {
       queue<TreeNode*>q;
        q.push(root);

       int maxSum=INT_MIN;
       int level=1;
       int result=1;

       while(!q.empty()){
         int sum=0;
         int size=q.size();

         for(int i=0; i<size; i++){
            TreeNode*total=q.front();
            q.pop();

            sum=sum+total->val;

            if(total->left) q.push(total->left);
            if(total->right) q.push(total->right);

         }
            if (sum>maxSum){
                maxSum = sum;
                result = level;
            }
          level++;
       }
       return result;

    }
};