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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mapping;
        unordered_map<int , int> pc_link;
        for(auto& it : descriptions){
            if(mapping.find(it[0]) == mapping.end()){
                TreeNode* temp = new TreeNode(it[0]);
                mapping[it[0]] = temp;
            }
            if(mapping.find(it[1]) == mapping.end()){
                TreeNode* temp2 = new TreeNode(it[1]);
                mapping[it[1]] = temp2;
            }
        }
        for(auto& it : descriptions){
            pc_link[it[1]] = it[0];
            if(it[2]) mapping[it[0]] -> left = mapping[it[1]];
            else mapping[it[0]] -> right = mapping[it[1]];
        }
        for(auto& it: mapping){
            if(pc_link.find(it.first) == pc_link.end())
                return it.second;
        }
        return NULL;
    }
};