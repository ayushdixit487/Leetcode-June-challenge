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
    int sumNumbers(TreeNode* root) {
       if(root==NULL)
           return 0;
        return sumNumbers(root ,"",0);
    }
    int sumNumbers(TreeNode* root ,string str ,int sum){
        if(root==NULL)
            return 0;
        str+=to_string(root->val);
        if(root->left ==NULL && root->right==NULL){
            
            sum += stoi(str);
           // str="";
        }
        sum  += sumNumbers(root->left , str,sum) 
                + sumNumbers(root->right,str,sum);
        return sum;
    }
};
