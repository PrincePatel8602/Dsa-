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
     int ans=0;
     vector<int>p(TreeNode*root){
        if(root==NULL){
            return {0,0};
        }
        vector<int>l=p(root->left);
        vector<int>r=p(root->right);
        int t=l[0];
        int c=l[1];
        int m=r[0];
        int d=r[1];
         if((t+m+root->val)/(c+d+1)==root->val){
            ans++;
         }
       return {root->val+t+m,c+d+1};
        
        
     }
    int averageOfSubtree(TreeNode* root) {
       vector<int>an= p(root);
       return ans;
    }
};