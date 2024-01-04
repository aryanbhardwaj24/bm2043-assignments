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

        TreeNode* lowest_common_ancestor(TreeNode* node, int a, int b) {
            if(!node) return NULL;
            if(node->val==a || node->val==b) return node;

            auto l = lowest_common_ancestor(node->left,a,b);
            auto r = lowest_common_ancestor(node->right,a,b);

            if(!l && !r) return NULL;
            if(l && r) return node;
            if(l) return l;
            return r;
        }
    public:
        binaryTree() {
            // this->root = take_input_recursively();
            this->root = take_input_levelwise();
        }

        void lowest_common_ancestor(int a, int b) {
            cout<<"LCA("<<a<<","<<b<<"): "<<lowest_common_ancestor(this->root,a,b)->val<<endl;
        }
};

int main () {
    binaryTree t;
    t.lowest_common_ancestor(4,5);
    t.lowest_common_ancestor(5,6);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/