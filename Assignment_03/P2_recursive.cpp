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

        void inorder(TreeNode* node, vector<int> &ans) {
            if(!node) return;
            inorder(node->left,ans);
            ans.push_back(node->val);
            inorder(node->right,ans);
        }

        void preorder(TreeNode* node, vector<int> &ans) {
            if(!node) return;
            ans.push_back(node->val);
            preorder(node->left,ans);
            preorder(node->right,ans);
        }

        void postorder(TreeNode* node, vector<int> &ans) {
            if(!node) return;
            postorder(node->left,ans);
            postorder(node->right,ans);
            ans.push_back(node->val);
        }
    public:
        binaryTree() {
            // this->root = take_input_recursively();
            this->root = take_input_levelwise();
        }

        void inorder() {
            vector<int> ans;
            inorder(root,ans);
            cout<<"InOrder Traversal: ";
            for(const auto &i:ans) cout<<i<<" ";
            cout<<endl;
        }

        void preorder() {
            vector<int> ans;
            preorder(root,ans);
            cout<<"PreOrder Traversal: ";
            for(const auto &i:ans) cout<<i<<" ";
            cout<<endl;
        }

        void postorder() {
            vector<int> ans;
            postorder(root,ans);
            cout<<"PostOrder Traversal: ";
            for(const auto &i:ans) cout<<i<<" ";
            cout<<endl;
        }
};

int main () {
    binaryTree t;
    t.inorder();
    t.preorder();
    t.postorder();
    return 0;
}

/*
                        Time Complexity     Space Complexity
InOrder Traversal:          O(n)                O(n) //Recursive Stack Space
PreOrder Traversal:         O(n)                O(n) //Recursive Stack Space
PostOrder Traversal:        O(n)                O(n) //Recursive Stack Space
*/