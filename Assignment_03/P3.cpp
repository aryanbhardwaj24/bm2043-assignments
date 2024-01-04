#include <bits/stdc++.h>
using namespace std;

class binaryTree;

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

        friend class binaryTree;
};

class binaryTree {
    private:
        TreeNode* root;

        TreeNode* take_input_recursively() {
            int data;
            cin>>data;
            if(data==-1) return NULL;

            TreeNode* root = new TreeNode(data);

            root->left = take_input_recursively();
            root->right = take_input_recursively();

            return root;
        }

        TreeNode* take_input_levelwise() {
            int data;
            cout<<"Enter root data: ";
            cin>>data;

            if(data==-1) return NULL;

            TreeNode* root = new TreeNode(data);

            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                auto var = q.front();
                q.pop();

                int l;
                cout<<"Enter the data of left child of "<<var->val<<" : ";
                cin>>l;
                if(l==-1) var->left = NULL;
                else {
                    TreeNode* temp = new TreeNode(l);
                    var->left = temp;
                    q.push(temp);
                }

                int r;
                cout<<"Enter the data of right child of "<<var->val<<" : ";
                cin>>r;
                if(r==-1) var->right = NULL;
                else {
                    TreeNode* temp = new TreeNode(r);
                    var->right = temp;
                    q.push(temp);
                }
            }
            return root;
        }

        void depth_first_search(TreeNode* node, vector<int> &ans) {
            if(!node) return;

            ans.push_back(node->val);
            depth_first_search(node->left,ans);
            depth_first_search(node->right,ans);
        }

        void level_order_traversal(TreeNode* node, vector<int> &ans) {
            if(!node) return;

            queue<TreeNode*> q;
            q.push(node);

            while(!q.empty()) {
                auto var = q.front();
                q.pop();

                ans.push_back(var->val);
                if(var->left) q.push(var->left);
                if(var->right) q.push(var->right);
            }
        }

        void zig_zag_traversal(TreeNode* node, vector<int> &ans) {
            if(!node) return;

            vector<vector<int>> v;
            vector<int> temp;
            int flag = 0;

            queue<TreeNode*> q;
            q.push(node);
            q.push(NULL);

            while(!q.empty()) {
                auto var = q.front();
                q.pop();
                if(!var) {
                    if(flag) reverse(temp.begin(),temp.end());
                    flag = 1-flag;
                    v.push_back(temp);
                    temp.clear();
                    if(!q.empty()) q.push(NULL);
                }
                else {
                    temp.push_back(var->val);
                    if(var->left) q.push(var->left);
                    if(var->right) q.push(var->right);
                }
            }

            for(const auto &i:v) {
                for(const auto &j:i) ans.push_back(j);
            }
        }
    public:
        binaryTree() {
            // this->root = take_input_recursively();
            this->root = take_input_levelwise();
        }

        void depth_first_search() {
            vector<int> ans;
            depth_first_search(root,ans);
            cout<<"Depth first search: ";
            for(const auto &i:ans) cout<<i<<" ";
            cout<<endl;
        }

        void level_order_traversal() {
            vector<int> ans;
            level_order_traversal(root,ans);
            cout<<"Level order traversal: ";
            for(const auto &i:ans) cout<<i<<" ";
            cout<<endl;
        }

        void zig_zag_traversal() {
            vector<int> ans;
            zig_zag_traversal(root,ans);
            cout<<"Zig zag traversal: ";
            for(const auto &i:ans) cout<<i<<" ";
            cout<<endl;
        }
};

int main () {
    binaryTree t;
    t.depth_first_search();
    t.level_order_traversal();
    t.zig_zag_traversal();
    return 0;
}

/*
                            Time Complexity         Space Complexity
Depth First Search:             O(n)                    O(n) //Recursive Stack Space
Level Order Traversal:          O(n)                    O(n)
Zig Zag Traversal:              O(n)                    O(n)
*/