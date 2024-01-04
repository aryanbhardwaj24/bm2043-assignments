#include <bits/stdc++.h>
using namespace std;

class BST;

class TreeNode {
    private:
        int val;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(int val) : val(val), left(NULL), right(NULL) {}

        ~TreeNode() {
            delete this->left;
            delete this->right;
        }

        friend class BST;
};

class BST {
    private:
        TreeNode* root;

        TreeNode* insert_node(TreeNode* node, int val) {
            if(!node) return new TreeNode(val);
            if(node->val<val) node->right = insert_node(node->right,val);
            else node->left = insert_node(node->left,val);

            return node;
        }

        TreeNode* right_min(TreeNode* node) {
            TreeNode* curr = node;
            while(curr->left) curr = curr->left;
            return curr;
        }

        TreeNode* delete_node(TreeNode* node, int val) {
            if(!node) return NULL;
            if(node->val==val) {
                if(!node->left && !node->right) return NULL;
                else if(!node->left && node->right) {
                    auto temp = node->right;
                    node->right = NULL;
                    delete node;
                    return temp;
                }
                else if(node->left && !node->right) {
                    auto temp = node->left;
                    node->left = NULL;
                    delete node;
                    return temp;
                }
                else {
                    auto temp = right_min(node->right);
                    node->val = temp->val;
                    node->right = delete_node(node->right,temp->val);
                    return node;
                }
            }
            else if(node->val<val) node->right = delete_node(node->right,val);
            else node->left = delete_node(node->left,val);
            return node;
        }
    public:
        BST() : root(NULL) {}

        ~BST() {
            delete this->root;
        }

        void insert_node(int val) {
            root = insert_node(root,val);
        }

        void delete_node(int val) {
            root = delete_node(root,val);
        }

        void print_tree_levelwise_modified() {
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);

            while(!q.empty()) {
                auto var = q.front();
                q.pop();

                if(!var) {
                    cout<<endl;
                    if(!q.empty()) q.push(NULL);
                }
                else {
                    cout<<var->val<<" ";
                    if(var->left) q.push(var->left);
                    if(var->right) q.push(var->right);
                }
            }
        }
};

int main () {
    BST t;
    t.insert_node(4);
    t.insert_node(2);
    t.insert_node(6);
    t.insert_node(1);
    t.insert_node(3);
    t.insert_node(5);
    t.print_tree_levelwise_modified();

    t.delete_node(4);
    t.print_tree_levelwise_modified();
    return 0;
}

/*
                Time Complexity     Space Complexity
insert_node:        O(h)                O(h)
delete_node:        O(h)                O(h)
                    - Here, 'h' denotes the height of BST.
                    - Also, 
                        - In worst case scenario (case of skewed tree), h~O(n)
                        - In case of balanced BST, h~O(log n)
*/