#include<iostream> 
#include<queue> 
#include<vector> 

using namespace std; 

struct TreeNode{
      int val; 
      TreeNode* left; 
      TreeNode* right; 
      TreeNode(): val(0), left(nullptr), right(nullptr){}
      TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}
      TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
}; 
class Solution{
public: 
      vector<int> rightSideView(TreeNode* root){
        vector<int> res; 
        if(root==nullptr) return res; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){
          int sz = q.size(); 
          for(int i=0; i<sz; ++i){
            TreeNode* node = q.front(); 
            q.pop(); 
            if(i==sz-1) res.push_back(node->val); 
            if(node->left) q.push(node->left); 
            if(node->right) q.push(node->right); 
          }
        }
        return res; 
      }
};
int main(){
  TreeNode* root = new TreeNode(1); 
  root->left = new TreeNode(2); 
  root->right= new TreeNode(3); 
  root->left->left = new TreeNode(4);
  root->left->left->left = new TreeNode(5);

  Solution sol; 
  vector<int> view = sol.rightSideView(root); 
  cout << "[ " ; 
  for(int s:view) cout << s << " , "; 
  cout << "]" << endl; 

  return 0; 
}
